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
#include "tinyxmlhelper.h"

namespace fs = boost::filesystem;

class DependencyManager
{
public:
    DependencyManager(const CmdOptions & options);
    fs::path buildDependencyPath();
    int info();
    int retrieve();
    int parse();
    int clean();
    static std::vector<fs::path> getChildrenDependencies(const fs::path & outputDirectory, const std::string & osPlatform, const std::string & filePrefix = "packagedependencies");
    static std::vector<Dependency> parse(const fs::path & dependenciesPath, const std::string & linkMode);

private:
    void generateConfigureFile(const fs::path &  rootFolderPath, const std::vector<Dependency> & deps);
    void parseConditionsFile(const fs::path &  rootFolderPath);
    std::vector<Dependency> filterConditionDependencies(const std::vector<Dependency> & depCollection);
    void retrieveDependencies(const fs::path & dependenciesFiles);
    void retrieveDependency(Dependency &  dependency);
    bool installDep(Dependency &  dependency, const std::string & source,
                    const fs::path & outputDirectory, const fs::path & libDirectory, const fs::path & binDirectory);
    void readInfos(const fs::path &  dependenciesFile);
    const CmdOptions & m_options;
    uint32_t m_indentLevel = 0;
    Cache m_cache;
    std::map<std::string,bool> m_defaultConditionsMap;

};

#endif // DEPENDENCYMANAGER_H
