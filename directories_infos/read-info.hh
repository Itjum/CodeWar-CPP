#pragma once

#include <fstream>

#include "directory-info.hh"

DirectoryInfo* read_info(std::ifstream& file);