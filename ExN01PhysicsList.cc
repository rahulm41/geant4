#include "globals.hh"
#include "ExN01PhysicsList.hh"
#include "G4ParticleDefinition.hh"

#include "G4ProcessManager.hh"
#include "G4ParticleTypes.hh"
#include "G4IonConstructor.hh"

/*
#include "G4ParticleDefinition.hh"
#include "G4Decay.hh"
#include "G4RadioactiveDecay.hh"
#include "G4GenericIon.hh"
#include "globals.hh"

//#include "ExN01PhysicsListParticles.hh"
#include "G4EmStandardPhysics.hh"
//#include "ExN01PhysListEmLowEnergy.hh"
#include "G4RegionStore.hh"
#include "G4Region.hh"
#include "G4ProductionCuts.hh"
#include "G4ParticleTable.hh"

#include "G4Gamma.hh"
#include "G4Electron.hh"
#include "G4Positron.hh"

#include "G4UnitsTable.hh"
#include "G4LossTableManager.hh"

#include "G4EmExtraPhysics.hh"
#include "G4QStoppingPhysics.hh"
#include "G4IonBinaryCascadePhysics.hh"
#include "G4RadioactiveDecayPhysics.hh"
#include "G4DecayPhysics.hh"
*/

ExN01PhysicsList::ExN01PhysicsList(): G4VUserPhysicsList()

{
  defaultCutValue = 0.1*mm;

   SetVerboseLevel(1);

}

ExN01PhysicsList::~ExN01PhysicsList()
{}

void ExN01PhysicsList::ConstructParticle()
{

  G4IonConstructor iConstructor;
  iConstructor.ConstructParticle();

  ConstructBosons();
  ConstructLeptons();
  ConstructBaryons();
}

void ExN01PhysicsList::ConstructBosons()
{
  // pseudo-particles
  G4Geantino::GeantinoDefinition();
  G4ChargedGeantino::ChargedGeantinoDefinition();

  // gamma
  G4Gamma::GammaDefinition();
// mesons
  G4PionPlus::PionPlusDefinition();
  G4PionMinus::PionMinusDefinition();
  G4PionZero::PionZeroDefinition();
  G4Eta::EtaDefinition();
  G4EtaPrime::EtaPrimeDefinition();
  G4KaonPlus::KaonPlusDefinition();
  G4KaonMinus::KaonMinusDefinition();
  G4KaonZero::KaonZeroDefinition();
  G4AntiKaonZero::AntiKaonZeroDefinition();
  G4KaonZeroLong::KaonZeroLongDefinition();
  G4KaonZeroShort::KaonZeroShortDefinition();
}

void ExN01PhysicsList::ConstructLeptons()
{
  // leptons
  //  e+/-
  G4Electron::ElectronDefinition();
  G4Positron::PositronDefinition();
  // nu_e
  G4NeutrinoE::NeutrinoEDefinition();
  G4AntiNeutrinoE::AntiNeutrinoEDefinition();
  // nu_mu
  G4NeutrinoMu::NeutrinoMuDefinition();
  G4AntiNeutrinoMu::AntiNeutrinoMuDefinition();

}
void ExN01PhysicsList::ConstructBaryons()
{
  //  baryons
  G4Proton::ProtonDefinition();
  G4AntiProton::AntiProtonDefinition();
  G4Neutron::NeutronDefinition();
  G4AntiNeutron::AntiNeutronDefinition();
}

void ExN01PhysicsList::ConstructProcess()
{
  AddTransportation();
  ConstructEM();
  ConstructGeneral();
}
/*
#include "G4ComptonScattering.hh"
#include "G4GammaConversion.hh"
#include "G4PhotoElectricEffect.hh"
#include "G4eMultipleScattering.hh"
#include "G4eIonisation.hh"
#include "G4eBremsstrahlung.hh"
#include "G4eplusAnnihilation.hh"

#include "G4MuIonisation.hh"
#include "G4MuBremsstrahlung.hh"
#include "G4MuPairProduction.hh"

#include "G4hIonisation.hh"
#include "G4ionIonisation.hh"

#include "G4Decay.hh"
#include "G4RadioactiveDecay.hh"
#include "G4GenericIon.hh"

#include "G4StepLimiter.hh"
#include "G4UserSpecialCuts.hh"


void ExN01PhysicsList::ConstructEM()
{
  theParticleIterator->reset();
  while( (*theParticleIterator)() ){
    G4ParticleDefinition* particle = theParticleIterator->value();
    G4ProcessManager* pmanager = particle->GetProcessManager();
    G4String particleName = particle->GetParticleName();

    if (particleName == "gamma") {
      // gamma
      pmanager->AddDiscreteProcess(new G4PhotoElectricEffect);
      pmanager->AddDiscreteProcess(new G4ComptonScattering);
      pmanager->AddDiscreteProcess(new G4GammaConversion);

    } else if (particleName == "e-") {
      //electron
      pmanager->AddProcess(new G4eMultipleScattering,-1, 1,1);
      pmanager->AddProcess(new G4eIonisation,       -1, 2,2);
      pmanager->AddProcess(new G4eBremsstrahlung,   -1, 3,3);

    } else if (particleName == "e+") {
      //positron
      pmanager->AddProcess(new G4eMultipleScattering,-1, 1,1);
      pmanager->AddProcess(new G4eIonisation,       -1, 2,2);
      pmanager->AddProcess(new G4eBremsstrahlung,   -1, 3,3);
      pmanager->AddProcess(new G4eplusAnnihilation,  0,-1,4);

    } else if( particleName == "mu+" || 
               particleName == "mu-"    ) {
      //muon  
      pmanager->AddProcess(new G4MuIonisation,      -1, 1,1);
      pmanager->AddProcess(new G4MuBremsstrahlung,  -1, 2,2);
      pmanager->AddProcess(new G4MuPairProduction,  -1, 3,3);       
     
    } else if( particleName == "alpha" || particleName == "GenericIon" ) { 
      pmanager->AddProcess(new G4ionIonisation,     -1, 1,1);

    } else if ((!particle->IsShortLived()) &&
	       (particle->GetPDGCharge() != 0.0) && 
	       (particle->GetParticleName() != "chargedgeantino")) {
      //all others charged particles except geantino
      pmanager->AddProcess(new G4hIonisation,       -1,1,1);
    }

  }
}
*/
// low EM model

/*
#include "G4LowEnergyCompton.hh"
#include "G4LowEnergyGammaConversion.hh"
#include "G4LowEnergyPhotoElectric.hh"
#include "G4LowEnergyRayleigh.hh"
*/
#include "G4PhotoElectricEffect.hh"
#include "G4LivermorePhotoElectricModel.hh"
#include "G4ComptonScattering.hh"
#include "G4LivermoreComptonModel.hh"
#include "G4GammaConversion.hh"
#include "G4LivermoreGammaConversionModel.hh"
#include "G4RayleighScattering.hh" 
#include "G4LivermoreRayleighModel.hh"




// e+
#include "G4eMultipleScattering.hh"
#include "G4eIonisation.hh"
#include "G4eBremsstrahlung.hh"
#include "G4eplusAnnihilation.hh"

#include "G4LowEnergyIonisation.hh"
#include "G4LowEnergyBremsstrahlung.hh"
#include "G4hLowEnergyIonisation.hh"
#include "G4Decay.hh"
#include "G4RadioactiveDecay.hh"
#include "G4GenericIon.hh"

#include "G4MuIonisation.hh"
#include "G4MuBremsstrahlung.hh"
#include "G4MuPairProduction.hh"

#include "G4StepLimiter.hh"
#include "G4UserSpecialCuts.hh"

void ExN01PhysicsList::ConstructEM()
{
  theParticleIterator->reset();
  while( (*theParticleIterator)() ){
    G4ParticleDefinition* particle = theParticleIterator->value();
    G4ProcessManager* pmanager = particle->GetProcessManager();
    G4String particleName = particle->GetParticleName();

    if (particleName == "gamma") {
      // gamma
       pmanager->AddDiscreteProcess(new G4LivermoreComptonModel);
     
      LePeprocess = new G4LivermorePhotoElectricModel();

      LePeprocess->ActivateAuger(true);
      LePeprocess->SetCutForLowEnSecPhotons(0.250 * keV);
      LePeprocess->SetCutForLowEnSecElectrons(0.250 * keV);

      pmanager->AddDiscreteProcess(LePeprocess);

      pmanager->AddDiscreteProcess(new G4LivermoreRayleighModel("Rayleigh"));


    } else if (particleName == "e-") {
      //electron
      pmanager->AddProcess(new G4eMultipleScattering,-1, 1,1);
      
      LeIoprocess = new G4LowEnergyIonisation("IONI");
      LeIoprocess->ActivateAuger(true);
      //eIoProcess = new G4eIonisation("stdIONI");
      LeIoprocess->SetCutForLowEnSecPhotons(0.1*keV);
      LeIoprocess->SetCutForLowEnSecElectrons(0.1*keV);
      pmanager->AddProcess(LeIoprocess, -1,  2, 2); 

      LeBrprocess = new G4LowEnergyBremsstrahlung();
      pmanager->AddProcess(LeBrprocess, -1, -1, 3);
      
      } else if (particleName == "e+") {
      //positron
      pmanager->AddProcess(new G4eMultipleScattering,-1, 1,1);
      pmanager->AddProcess(new G4eIonisation,      -1, 2,2);
      pmanager->AddProcess(new G4eBremsstrahlung,   -1,-1,3);
      pmanager->AddProcess(new G4eplusAnnihilation,  0,-1,4);

      pmanager->AddProcess(new G4eMultipleScattering,-1, 1,1);
      pmanager->AddProcess(new G4eIonisation,       -1, 2,2);
      pmanager->AddProcess(new G4eBremsstrahlung,   -1, 3,3);

    } else if (particleName == "proton") {
      //proton
      G4hLowEnergyIonisation* hIoni = new G4hLowEnergyIonisation;
      hIoni->SetFluorescence(true);
      pmanager->AddProcess(new G4eMultipleScattering,-1,1,1);
      pmanager->AddProcess(hIoni,-1, 2,2);
    }
    else if (   particleName == "alpha" )
      {
	
	pmanager->AddProcess(new G4eMultipleScattering,-1,1,1);
	G4hLowEnergyIonisation* iIon = new G4hLowEnergyIonisation() ;
	pmanager->AddProcess(iIon,-1,2,2);
      }

  }
}


// Penelope model
/*
//#include "PhysListEmPenelope.hh"
#include "G4ParticleDefinition.hh"

#include "G4PenelopeCompton.hh"
#include "G4PenelopeGammaConversion.hh"
#include "G4PenelopePhotoElectric.hh"
#include "G4PenelopeRayleigh.hh"

#include "G4MultipleScattering.hh"

#include "G4PenelopeIonisation.hh"
#include "G4PenelopeBremsstrahlung.hh"
#include "G4PenelopeAnnihilation.hh"

#include "G4MuIonisation.hh"
#include "G4MuBremsstrahlung.hh"
#include "G4MuPairProduction.hh"

#include "G4hIonisation.hh"
#include "G4ionIonisation.hh"
#include "G4Decay.hh"
#include "G4RadioactiveDecay.hh"
#include "G4GenericIon.hh"

#include "G4StepLimiter.hh"
#include "G4UserSpecialCuts.hh"

void ExN01PhysicsList::ConstructEM()

{
  // Add Penelope or standard EM Processes

  theParticleIterator->reset();
  while( (*theParticleIterator)() ){
    G4ParticleDefinition* particle = theParticleIterator->value();
    G4ProcessManager* pmanager = particle->GetProcessManager();
    G4String particleName = particle->GetParticleName();
     
    if (particleName == "gamma") {
      // gamma         
      pmanager->AddDiscreteProcess(new G4PenelopePhotoElectric);
      pmanager->AddDiscreteProcess(new G4PenelopeCompton);
      pmanager->AddDiscreteProcess(new G4PenelopeGammaConversion);
      pmanager->AddDiscreteProcess(new G4PenelopeRayleigh);
      
    } else if (particleName == "e-") {
      //electron
      pmanager->AddProcess(new G4MultipleScattering,     -1, 1, 1);
      pmanager->AddProcess(new G4PenelopeIonisation,     -1, 2, 2);
      pmanager->AddProcess(new G4PenelopeBremsstrahlung, -1,-1, 3);
	    
    } else if (particleName == "e+") {
      //positron
      pmanager->AddProcess(new G4MultipleScattering,     -1, 1, 1);
      pmanager->AddProcess(new G4PenelopeIonisation,     -1, 2, 2);
      pmanager->AddProcess(new G4PenelopeBremsstrahlung, -1,-1, 3);      
      pmanager->AddProcess(new G4PenelopeAnnihilation,    0,-1, 4);
      
    } else if( particleName == "mu+" || 
               particleName == "mu-"    ) {
      //muon  
      pmanager->AddProcess(new G4MuIonisation,       -1, 1, 1);
      pmanager->AddProcess(new G4MuBremsstrahlung,   -1, 2, 2);
      pmanager->AddProcess(new G4MuPairProduction,   -1, 3, 3);       
     
    } else if( particleName == "alpha" || particleName == "GenericIon" ) { 
      pmanager->AddProcess(new G4ionIonisation,      -1, 1, 1);
     
    } else if ((!particle->IsShortLived()) &&
	       (particle->GetPDGCharge() != 0.0) && 
	       (particle->GetParticleName() != "chargedgeantino")) {
      //all others charged particles except geantino
      pmanager->AddProcess(new G4hIonisation,        -1, 1, 1);
    }
 
  }
}
*/


void ExN01PhysicsList::ConstructGeneral()

{
  // Add Decay Process

  G4Decay* fDecayProcess = new G4Decay();
  G4RadioactiveDecay*  theRadioactiveDecay = new G4RadioactiveDecay();
  G4GenericIon* ion = G4GenericIon::GenericIon();
  theParticleIterator->reset();
  while( (*theParticleIterator)() ){
    G4ParticleDefinition* particle = theParticleIterator->value();
    G4ProcessManager* pmanager = particle->GetProcessManager();

    if (particle == ion) {
      pmanager->AddProcess(theRadioactiveDecay, 0, -1, 3);

    } else if (fDecayProcess->IsApplicable(*particle)) { 

      pmanager ->AddProcess(fDecayProcess);

      // set ordering for PostStepDoIt and AtRestDoIt
      pmanager ->SetProcessOrdering(fDecayProcess, idxPostStep);
      pmanager ->SetProcessOrdering(fDecayProcess, idxAtRest);

    }
  }
}



void ExN01PhysicsList::SetCuts()
{
  //  " G4VUserPhysicsList::SetCutsWithDefault" method sets 
  //   the default cut value for all particle types 
  //  SetCutsWithDefault();   

//  SetCutValue(1.0*keV, "gamma");
//  SetCutValue(1.0*keV, "e-");
//  SetCutValue(1.0*keV, "e+");

//  defaultCutValue = 1*mm;

  SetCutValue(defaultCutValue, "gamma");
  SetCutValue(defaultCutValue, "e-");
  SetCutValue(defaultCutValue, "e+");

  if (verboseLevel>0) DumpCutValuesTable();

}

