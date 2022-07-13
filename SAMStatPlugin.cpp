#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "SAMStatPlugin.h"

void SAMStatPlugin::input(std::string file) {
 inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string filename;
   ifile >> filename;
   if (filename.size() > 0)
   fastqFiles.push_back(filename);
 }
}

void SAMStatPlugin::run() {
   
}

void SAMStatPlugin::output(std::string file) {
 // alpha_diversity.py -i filtered_otu_table.biom -m observed_species,chao1,shannon,PD_whole_tree -t rep_set.tre -o alpha.txt
   std::string command = "samstat ";
   for (int i = 0; i < fastqFiles.size(); i++) {
      command += std::string(PluginManager::prefix())+"/"+fastqFiles[i] + " ";
   }
 std::cout << command << std::endl;

 system(command.c_str());
}

PluginProxy<SAMStatPlugin> SAMStatPluginProxy = PluginProxy<SAMStatPlugin>("SAMStat", PluginManager::getInstance());
