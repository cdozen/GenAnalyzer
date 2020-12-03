#!/bin/bash
echo "Starting job on " `date` #Date/time of start of job
echo "Running on: `uname -a`" #Condor job is running on this node
echo "System software: `cat /etc/redhat-release`" #Operating System on that node
source /cvmfs/cms.cern.ch/cmsset_default.sh  ## if a bash script, use .sh instead of .csh
### for case 1. EOS have the following line, otherwise remove this line in case 2.
xrdcp -s root://cmseos.fnal.gov//store/user/cdozen/CMSSW1025.tgz .
tar -xf CMSSW1025.tgz
rm CMSSW1025.tgz
export SCRAM_ARCH slc7_amd64_gcc700
cd CMSSW_10_2_5/src/
scramv1 b ProjectRename
eval `scramv1 runtime -sh` # cmsenv is an alias not on the workers
cd ${_CONDOR_SCRATCH_DIR}
root -q -b -l FILENAME
rm -rf CMSSW_10_2_5
