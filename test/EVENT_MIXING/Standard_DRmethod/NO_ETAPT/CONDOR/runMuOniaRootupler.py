import FWCore.ParameterSet.Config as cms
process = cms.Process("Rootuple")

process.load("TrackingTools/TransientTrack/TransientTrackBuilder_cfi")
process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
#process.load("Configuration.Geometry.GeometryIdeal_cff")
process.load("Configuration.StandardSequences.MagneticField_AutoFromDBCurrent_cff")
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')
from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, '80X_dataRun2_2016SeptRepro_v7', '')			#for 2016 
#process.GlobalTag = GlobalTag(process.GlobalTag, '94X_dataRun2_ReReco_EOY17_v6', '')			#for 2017 Rereco
#process.GlobalTag = GlobalTag(process.GlobalTag, '102X_dataRun2_Prompt_v4', '')			#for 2018 PromptReco
#process.GlobalTag = GlobalTag(process.GlobalTag, '102X_dataRun2_Sep2018Rereco_v1', '')			#for 2018 Rereco

process.load("FWCore.MessageLogger.MessageLogger_cfi")
#process.MessageLogger.cerr.FwkReport.reportEvery = 500

process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(-1))

process.source = cms.Source("PoolSource",
fileNames = cms.untracked.vstring('root://cmsxrootd.fnal.gov/INPUTPATH1/INPUTFILE')
)


process.TFileService = cms.Service("TFileService",
        fileName = cms.string('Rootuple_NUMBER.root'),
)

process.options   = cms.untracked.PSet( wantSummary = cms.untracked.bool(True))

process.load('FourMuonAna.Onia.MuMuGammaRootupler_cfi')
process.p = cms.Path(process.rootuple)

process.rootuple.upsilon_mass = cms.double(9.4603)
process.rootuple.triggerCuts = cms.uint32(36)
process.rootuple.isMC = cms.bool(False)                 # is mc?
process.rootuple.onia_mass_cuts = cms.vdouble(0.1,500)    # you may need to adjust this
#process.rootuple.SecondSource.fileNames = cms.untracked.vstring(
#	  'file:/eos/uscms/store/user/l1upgrades/Run2017/fourmuon/ZeroBias/BPHSkim-v4-Run2017F-17Nov2017-v1/180314_055941/0000/BPHSkim_426.root'
#	  )



