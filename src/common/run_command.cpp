// Copyright (c) 2022 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <common/run_command.h>

#include <univalue.h>

UniValue RunCommandParseJSON(const std::string& str_command, const std::string& str_std_in)
{
    throw std::runtime_error("Compiled without external signing support (required for external signing).");
}
