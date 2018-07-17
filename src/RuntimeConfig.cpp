/*************************************************************************
* MCModCrafter Program to help introduce people to minecraft modding and
* to speed development time via logic visualization.
*
* Copyright (C) 2017 Edward Callahan
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <https://www.gnu.org/licenses/>.
*************************************************************************/

#include <stdafx.h>
#include "RuntimeConfig.h"

RuntimeConfig* RuntimeConfig::Instance()
{
    static RuntimeConfig* config = nullptr;
    if(config == nullptr)
    {
        config = new RuntimeConfig;
        if(!config->Load(":/MCModCrafter/runtimeconfig.json"))
        {
            L_FATAL("Failed to load runtime configuration.");
            throw std::runtime_error("Could not load a crucial configuration file.");
        }
    }
    return config;
}
