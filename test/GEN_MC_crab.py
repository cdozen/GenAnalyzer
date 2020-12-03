import FWCore.ParameterSet.Config as cms
process = cms.Process("GenAnalyzer")                                                                                                                
process.load("FWCore.MessageService.MessageLogger_cfi")
process.load('Configuration/StandardSequences/Services_cff')
process.load('Configuration/StandardSequences/GeometryExtended_cff')
process.load('Configuration/StandardSequences/MagneticField_38T_cff')
process.load('Configuration/StandardSequences/FrontierConditions_GlobalTag_cff')
globalTag = ""
globalTag = '102X_upgrade2018_realistic_v15'
process.GlobalTag.globaltag = cms.string(globalTag)
from Configuration.AlCa.GlobalTag_condDBv2 import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, globalTag, '')

process.load("Configuration.EventContent.EventContent_cff")
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.source = cms.Source("PoolSource",
    duplicateCheckMode = cms.untracked.string('noDuplicateCheck'),
    #skipEvents = cms.untracked.uint32(842),
    fileNames = cms.untracked.vstring(
    #"file:/eos/uscms/store/group/l1upgrades/MC2020DPSToJJ_NoGenCut/DPSToJJ_13TeV_pythia8/crab_RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-GENSIM-DPSTo4mu-noGenCut-v2/200709_035732/0000/FourMu_DPSJJMC_102.root"
       # "file:/eos/uscms/store/group/l1upgrades/MC2020SPSToYY_NoGenCut/SPSToYY_13TeV_pythia8/crab_RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-GENSIM-SPSTo4mu-noGenCut-v1/200709_040832/0002/FourMu_qqorggMC_2600.root",
       # "file:/eos/uscms/store/group/l1upgrades/MC2020SPSToYY_NoGenCut/SPSToYY_13TeV_pythia8/crab_RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-GENSIM-SPSTo4mu-noGenCut-v1/200709_040832/0003/FourMu_qqorggMC_3000.root"    
)
)

# ----------------------------------------------------------------------
# Output root file (monitoring histograms)
# ----------------------------------------------------------------------
process.TFileService=cms.Service('TFileService',
                                fileName=cms.string('ROOTFiles_GEN_MC_DPStoJJ_withGenCUT_7Nov2020.root')
                                )

from FWCore.Modules.printContent_cfi import *
#process.dumpEv = FWCore.Modules.printContent_cfi.printContent.clone()
process.printDebug = cms.EDAnalyzer("EventContentAnalyzer")



process.GenAnalyzer = cms.EDAnalyzer('GenAnalyzer',
         genParticlesAOD = cms.InputTag('genParticles') 
)     
process.p = cms.Path(
         #process.hiGenParticles *
        #process.genParticles *
        process.GenAnalyzer
)
 

