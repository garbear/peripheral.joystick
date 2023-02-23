/*
 *  Copyright (C) 2016-2021 Garrett Brown
 *  Copyright (C) 2016-2021 Team Kodi
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSE.md for more information.
 */

#pragma once

#include "PrimitiveConfiguration.h"
#include "StorageTypes.h"
#include "buttonmapper/ButtonMapTypes.h"

#include <map>
#include <string>

namespace JOYSTICK
{
  class CDevice;

  class CDeviceConfiguration
  {
  public:
    CDeviceConfiguration() = default;
    ~CDeviceConfiguration(void) = default;

    void Reset(void);

    bool IsEmpty() const;

    const std::string& GetAppearance(void) const { return m_appearance; }
          AxisConfigurationMap&   Axes(void)                       { return m_axes; }
    const AxisConfigurationMap&   Axes(void) const                 { return m_axes; }
    const AxisConfiguration&      Axis(unsigned int index) const;
          ButtonConfigurationMap& Buttons(void)                    { return m_buttons; }
    const ButtonConfigurationMap& Buttons(void) const              { return m_buttons; }
    const ButtonConfiguration&    Button(unsigned int index) const;
    PrimitiveVector               GetIgnoredPrimitives() const;
    void                          GetAxisConfigs(FeatureVector& features) const;
    void                          GetAxisConfig(kodi::addon::DriverPrimitive& primitive) const;

    void SetAppearance(const std::string& controllerId) { m_appearance = controllerId; }
    void SetAxis(unsigned int index, const AxisConfiguration& config)     { m_axes[index] = config; }
    void SetButton(unsigned int index, const ButtonConfiguration& config) { m_buttons[index] = config; }
    void SetAxisConfigs(const FeatureVector& features);
    void SetAxisConfig(const kodi::addon::DriverPrimitive& primitive);
    void SetIgnoredPrimitives(const PrimitiveVector& primitives);

  private:
    // Configuration parameters
    std::string m_appearance;
    AxisConfigurationMap m_axes;
    ButtonConfigurationMap m_buttons;
  };
}
