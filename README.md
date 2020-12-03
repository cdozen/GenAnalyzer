# GenAnalyzer
# GenAnalzer_step1
Gen level Ntuple producer for Double Jpsi

cmsrel CMSSW_10_2_5 

cd CMSSW_10_2_5/src

cmsenv

mkdir GenAnalyzer

cd GenAnalyzer

git clone https://github.com/cdozen/GenAnalzer.git

scram b -j24

main code :

GenAnalzer/plugins/GenAnalyzer.cc 

To run it locally:

Add Gen Level dataset in 

GenAnalzer/test/GenAnalyzer_cfg.py 

run : 

cmsRun GenAnalyzer_cfg.py

Submit jobs via crab: 

1-for a single dataset : crab submit -c crabconfig_MC_jpsi.py

Add dataset name:

L#20

config.Data.inputDataset =' Datasetname....'

Add output files path :

L#24 

config.Data.outLFNDirBase = '/store/user/username/Folder/Subfolder2/'

2-for multiple dataset:  multicrab_MC or multicrab_MCJJ

Add output files path :

L#95

config.Data.outLFNDirBase = '/store/user/username/Folder/Subfolder2/'

Add Dataset name in 

L#102 

inputDatasets = [Datasetnames....]

Submit jobs:

./multicrab_MC --crabCmd=submit


PLOTMAKER:

# GenAnalyzer_step2

Gen level plotmaker

to run the plotmaker code:

add ntuples in main.cpp

add cuts (pt/eta,etc..) in gen_tree.C

make

./main.exe

outputfile will be created..


EVENT_MIXING:

# GenAnalyzer_step3

Gen level event mixing

Add output root file from step2:

in DoubleJpsi_mix.cxx

run :

root -l DoubleJpsi_mix.cxx

it will create mass spectrum plots for Double Jpsi, 4Muon and mixing..


