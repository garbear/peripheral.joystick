/*
 *      Copyright (C) 2014-2015 Garrett Brown
 *      Copyright (C) 2014-2015 Team XBMC
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */
#pragma once

#include "storage/Device.h"

#include "kodi/kodi_peripheral_utils.hpp"

#include <map>

namespace JOYSTICK
{
  class CDeviceDatabase
  {
  public:
    CDeviceDatabase(void) { }
    virtual ~CDeviceDatabase(void) { }

    /*!
     * \brief Get the driver record associated with the given driver info
     * \param joystick The known driver info
     * \return The driver record
     *
     * If joystick is missing fields, the returned record
     */
    virtual bool GetDevice(const ADDON::Joystick& joystick, CDevice& record);

  protected:
    typedef std::map<CDevice, CDevice> DeviceMap; // Partial driver information -> full driver information

    DeviceMap m_driverRecords;
  };
}