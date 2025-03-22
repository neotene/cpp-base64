//
//  base64 encoding and decoding with C++.
//  Version: 2.rc.09 (release candidate)
//

#ifndef BASE64_H_C0CE2A47_D10E_42C9_A27C_C883944E704A
#define BASE64_H_C0CE2A47_D10E_42C9_A27C_C883944E704A

#include <string>

#include "base64/config.hpp"

#include <string_view>
//
// Interface with std::string_view rather than const std::string&
// Requires C++17
// Provided by Yannic Bonenberger (https://github.com/Yannic)
//
BASE64_API std::string base64_encode(std::string_view s, bool url = false);
BASE64_API std::string base64_encode_pem(std::string_view s);
BASE64_API std::string base64_encode_mime(std::string_view s);

BASE64_API std::string base64_decode(std::string_view s,
                                     bool remove_linebreaks = false);

#endif /* BASE64_H_C0CE2A47_D10E_42C9_A27C_C883944E704A */
