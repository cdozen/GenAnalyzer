#!/bin/bash
cmsswDir="/uscms/home/cdozen/nobackup/Saving/CMSSW_10_2_5/src/"
inputFiles=""

myeospath1="/store/user/cdozen/FourMuon_Analysis/GEN_MC/Double_Jpsi/Noetaptrootfiles"

j=0
for files in `ls /eos/uscms${myeospath1} | grep root`
do 
	inputFiles=$files;
	echo $inputFiles;
	jobNb=${j};
	let j=${j}+1;
	jobCScript="DoubleJpsi_mix_noetapt_${jobNb}.cxx";
	scriptName="Run_${jobNb}.sh";
	condorScriptName="runOnCondor_${jobNb}";
	cat DoubleJpsi_mix_noetapt.cxx | sed "s:INPUTPATH1:${myeospath1}:" | sed "s-INPUTFILE-${inputFiles}-" | sed "s/NUMBER/${jobNb}/g" > ${jobCScript} ;
	cat Run.sh | sed "s-FILENAME-${jobCScript}-" > ${scriptName};
	chmod +x ${scriptName}
	cat runOnCondor | sed "s/SCRIPT/${scriptName}/" | sed "s/JOBC/${jobCScript}/" > ${condorScriptName}
	condor_submit ${condorScriptName}
done
