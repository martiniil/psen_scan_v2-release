// Copyright (c) 2020 Pilz GmbH & Co. KG
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include "psen_scan_v2/start_request.h"

namespace psen_scan_v2
{
static constexpr TenthOfDegree MASTER_RESOLUTION{ TenthOfDegree(2u) };

namespace start_request
{
Message::Message(const ScannerConfiguration& scanner_configuration)
  : host_ip_(scanner_configuration.hostIp())
  , host_udp_port_data_(scanner_configuration.hostUDPPortData())  // Write is deduced by the scanner
  , master_device_settings_(ScannerId::master, scanner_configuration.diagnosticsEnabled())
  , master_(scanner_configuration.scanRange(), MASTER_RESOLUTION)
{
}

}  // namespace start_request
}  // namespace psen_scan_v2
