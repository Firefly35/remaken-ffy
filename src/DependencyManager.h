/**
 * @copyright Copyright (c) 2019 B-com http://www.b-com.com/
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * @author Loïc Touraine
 *
 * @file
 * @brief description of file
 * @date 2019-11-15
 */

#ifndef DEPENDENCYMANAGER_H
#define DEPENDENCYMANAGER_H

#include <string>
#include <vector>
#include <iostream>
#include <boost/filesystem.hpp>
#include "Dependency.h"
#include "CmdOptions.h"
#include "Cache.h"

namespace fs = boost::filesystem;
namespace po = boost::program_options;

class DependencyManager
{
public:
    DependencyManager(const CmdOptions & options);
    fs::path buildDependencyPath();
    int retrieve();
    int parse();
    int bundle();

private:
    std::vector<Dependency> parse(const fs::path & dependenciesPath);
    void bundleDependencies(const fs::path & dependenciesFiles);
    void bundleDependency(const Dependency & dep);
    void retrieveDependencies(const fs::path & dependenciesFiles);
    void retrieveDependency(const Dependency &  dependency);
    std::vector<fs::path> getChildrenDependencies(const Dependency & dependency, const fs::path & outputDirectory);
    CmdOptions m_options;
    Cache m_cache;

};

#endif // DEPENDENCYMANAGER_H
