/***************************************************************************************************
 * Xidi
 *   DirectInput interface for XInput controllers.
 ***************************************************************************************************
 * Authored by Samuel Grossman
 * Copyright (c) 2016-2023
 ***********************************************************************************************//**
 * @file Mapper.h
 *   Declaration of functionality used to implement mappings of an entire XInput controller
 *   layout to a virtual controller layout.
 **************************************************************************************************/

#pragma once

#include <memory>
#include <string_view>

#include "ApiBitSet.h"
#include "ApiWindows.h"
#include "ControllerTypes.h"
#include "ElementMapper.h"
#include "ForceFeedbackTypes.h"

/// Computes the index of the specified named controller element in the unnamed array representation
/// of the element map.
#define ELEMENT_MAP_INDEX_OF(element)                                                              \
  (static_cast<unsigned int>(                                                                      \
      offsetof(::Xidi::Controller::Mapper::UElementMap, named.##element) /                         \
      (offsetof(::Xidi::Controller::Mapper::UElementMap, all[1]) -                                 \
       offsetof(::Xidi::Controller::Mapper::UElementMap, all[0]))))

/// Computes the index of the specified named force feedback actuator element in the unnamed array
/// representation of the force feedback actuator map.
#define FFACTUATOR_MAP_INDEX_OF(ffactuator)                                                        \
  (static_cast<unsigned int>(                                                                      \
      offsetof(::Xidi::Controller::Mapper::UForceFeedbackActuatorMap, named.##ffactuator) /        \
      (offsetof(::Xidi::Controller::Mapper::UForceFeedbackActuatorMap, all[1]) -                   \
       offsetof(::Xidi::Controller::Mapper::UForceFeedbackActuatorMap, all[0]))))

namespace Xidi
{
  namespace Controller
  {
    /// Maps a physical controller layout to a virtual controller layout.
    /// Each instance of this class represents a different virtual controller layout.
    class Mapper
    {
    public:

      /// Physical controller element mappers, one per controller element.
      /// For controller elements that are not used, a value of `nullptr` may be used instead.
      struct SElementMap
      {
        std::unique_ptr<const IElementMapper> stickLeftX = nullptr;
        std::unique_ptr<const IElementMapper> stickLeftY = nullptr;
        std::unique_ptr<const IElementMapper> stickRightX = nullptr;
        std::unique_ptr<const IElementMapper> stickRightY = nullptr;
        std::unique_ptr<const IElementMapper> dpadUp = nullptr;
        std::unique_ptr<const IElementMapper> dpadDown = nullptr;
        std::unique_ptr<const IElementMapper> dpadLeft = nullptr;
        std::unique_ptr<const IElementMapper> dpadRight = nullptr;
        std::unique_ptr<const IElementMapper> triggerLT = nullptr;
        std::unique_ptr<const IElementMapper> triggerRT = nullptr;
        std::unique_ptr<const IElementMapper> buttonA = nullptr;
        std::unique_ptr<const IElementMapper> buttonB = nullptr;
        std::unique_ptr<const IElementMapper> buttonX = nullptr;
        std::unique_ptr<const IElementMapper> buttonY = nullptr;
        std::unique_ptr<const IElementMapper> buttonLB = nullptr;
        std::unique_ptr<const IElementMapper> buttonRB = nullptr;
        std::unique_ptr<const IElementMapper> buttonBack = nullptr;
        std::unique_ptr<const IElementMapper> buttonStart = nullptr;
        std::unique_ptr<const IElementMapper> buttonLS = nullptr;
        std::unique_ptr<const IElementMapper> buttonRS = nullptr;

        std::unique_ptr<const IElementMapper> slider = nullptr;
        std::unique_ptr<const IElementMapper> dial = nullptr;

        std::unique_ptr<const IElementMapper> extra1 = nullptr;
        std::unique_ptr<const IElementMapper> extra2 = nullptr;

        std::unique_ptr<const IElementMapper> extraButton1 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton2 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton3 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton4 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton5 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton6 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton7 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton8 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton9 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton10 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton11 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton12 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton13 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton14 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton15 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton16 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton17 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton18 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton19 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton20 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton21 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton22 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton23 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton24 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton25 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton26 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton27 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton28 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton29 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton30 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton31 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton32 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton33 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton34 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton35 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton36 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton37 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton38 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton39 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton40 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton41 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton42 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton43 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton44 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton45 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton46 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton47 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton48 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton49 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton50 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton51 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton52 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton53 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton54 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton55 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton56 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton57 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton58 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton59 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton60 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton61 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton62 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton63 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton64 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton65 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton66 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton67 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton68 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton69 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton70 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton71 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton72 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton73 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton74 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton75 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton76 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton77 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton78 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton79 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton80 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton81 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton82 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton83 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton84 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton85 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton86 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton87 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton88 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton89 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton90 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton91 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton92 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton93 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton94 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton95 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton96 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton97 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton98 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton99 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton100 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton101 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton102 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton103 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton104 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton105 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton106 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton107 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton108 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton109 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton110 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton111 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton112 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton113 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton114 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton115 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton116 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton117 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton118 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton119 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton120 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton121 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton122 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton123 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton125 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton126 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton127 = nullptr;
        std::unique_ptr<const IElementMapper> extraButton128 = nullptr;
      };

      /// Physical force feedback actuator mappers, one per force feedback actuator.
      /// For force feedback actuators that are not used, the `valid` bit is set to 0.
      /// Names correspond to the enumerators in the #ForceFeedback::EActuator enumeration.
      struct SForceFeedbackActuatorMap
      {
        ForceFeedback::SActuatorElement leftMotor;
        ForceFeedback::SActuatorElement rightMotor;
        ForceFeedback::SActuatorElement leftImpulseTrigger;
        ForceFeedback::SActuatorElement rightImpulseTrigger;
      };

      static_assert(
          sizeof(SForceFeedbackActuatorMap) <= 8, "Data structure size constraint violation.");

      /// Dual representation of a controller element map. Intended for internal use only.
      /// In one representation the elements all have names for element-specific access.
      /// In the other, all the elements are collapsed into an array for easy iteration.
      union UElementMap
      {
        SElementMap named;
        std::unique_ptr<const IElementMapper>
            all[sizeof(SElementMap) / sizeof(std::unique_ptr<const IElementMapper>)];

        static_assert(sizeof(named) == sizeof(all), "Element map field mismatch.");

        constexpr UElementMap(void) : named() {}

        UElementMap(const UElementMap& other);

        inline UElementMap(UElementMap&& other) noexcept : named(std::move(other.named)) {}

        inline UElementMap(SElementMap&& named) : named(std::move(named)) {}

        inline ~UElementMap(void)
        {
          named.~SElementMap();
        }

        UElementMap& operator=(const UElementMap& other);

        UElementMap& operator=(UElementMap&& other);
      };

      /// Dual representation of a force feedback actuator map. Intended for internal use only.
      /// In one representation the elements all have names for element-specific access.
      /// In the other, all the elements are collapsed into an array for easy iteration.
      union UForceFeedbackActuatorMap
      {
        SForceFeedbackActuatorMap named;
        ForceFeedback::SActuatorElement all[(int)ForceFeedback::EActuator::Count];

        constexpr UForceFeedbackActuatorMap(void) : named() {}

        constexpr UForceFeedbackActuatorMap(const UForceFeedbackActuatorMap& other)
            : named(other.named)
        {}

        constexpr UForceFeedbackActuatorMap(const SForceFeedbackActuatorMap& actuatorMap)
            : named(actuatorMap)
        {}

        inline ~UForceFeedbackActuatorMap(void)
        {
          named.~SForceFeedbackActuatorMap();
        }

        constexpr UForceFeedbackActuatorMap& operator=(const UForceFeedbackActuatorMap& other)
        {
          named = other.named;
          return *this;
        }
      };

      static_assert(
          sizeof(UForceFeedbackActuatorMap::named) == sizeof(UForceFeedbackActuatorMap::all),
          "Force feedback actuator field mismatch.");

      /// Set of axes that must be present on all virtual controllers.
      /// Contents are based on expectations of both DirectInput and WinMM state data structures.
      /// If no element mappers contribute to these axes then they will be continually reported as
      /// being in a neutral position.
      static constexpr BitSetEnum<EAxis> kRequiredAxes = {(int)EAxis::X, (int)EAxis::Y};

      /// Set of axes that must be present on all virtual controllers and support force feedback.
      /// If not mapped to a physical actuator, these axes will ignore all force feedback output.
      static constexpr BitSetEnum<EAxis> kRequiredForceFeedbackAxes = kRequiredAxes;

      /// Minimum number of buttons that must be present on all virtual controllers.
      static constexpr int kMinNumButtons = 2;

      /// Whether or not virtual controllers must contain a POV hat.
      static constexpr bool kIsPovRequired = false;

      /// Default force feedback actuator configuration.
      static constexpr ForceFeedback::SActuatorElement kDefaultForceFeedbackActuator = {
          .isPresent = true,
          .mode = ForceFeedback::EActuatorMode::MagnitudeProjection,
          .magnitudeProjection = {.axisFirst = EAxis::X, .axisSecond = EAxis::Y}};

      /// Default force feedback actuator map.
      /// Used whenever a force feedback actuator map is not provided.
      static constexpr SForceFeedbackActuatorMap kDefaultForceFeedbackActuatorMap = {
          .leftMotor = kDefaultForceFeedbackActuator, .rightMotor = kDefaultForceFeedbackActuator};

      /// Each controller element must supply a unique element mapper which becomes owned by this
      /// object. For controller elements that are not used, `nullptr` may be set instead.
      Mapper(
          const std::wstring_view name,
          SElementMap&& elements,
          SForceFeedbackActuatorMap forceFeedbackActuators = kDefaultForceFeedbackActuatorMap);

      /// Does not require or register a name for this mapper. This version is primarily useful for
      /// testing. Requires that a unique mapper be specified for each controller element, which in
      /// turn becomes owned by this object. For controller elements that are not used, `nullptr`
      /// may be set instead.
      Mapper(
          SElementMap&& elements,
          SForceFeedbackActuatorMap forceFeedbackActuators = kDefaultForceFeedbackActuatorMap);

      /// In general, mapper objects should not be destroyed once created.
      /// However, tests may create mappers as temporaries that end up being destroyed.
      ~Mapper(void);

      /// Dumps information about all registered mappers.
      static void DumpRegisteredMappers(void);

      /// Retrieves and returns a pointer to the mapper object whose name is specified.
      /// Mapper objects are created and managed internally, so this operation does not dynamically
      /// allocate or deallocate memory, nor should the caller attempt to free the returned pointer.
      /// @param [in] mapperName Name of the desired mapper. Supported built-in values are defined
      /// in "MapperDefinitions.cpp" as mapper instances, but more could be built and registered at
      /// runtime.
      /// @return Pointer to the mapper of specified name, or `nullptr` if said mapper is
      /// unavailable.
      static const Mapper* GetByName(std::wstring_view mapperName);

      /// Retrieves and returns a pointer to the mapper object whose type is read from the
      /// configuration file for the specified controller identifier. If no mapper specified there,
      /// then the default mapper type is used instead.
      /// @param [in] controllerIdentifier Identifier of the controller for which a mapper is
      /// requested.
      static const Mapper* GetConfigured(TControllerIdentifier controllerIdentifier);

      /// Retrieves and returns a pointer to the default mapper object.
      /// @return Pointer to the default mapper object, or `nullptr` if there is no default.
      static inline const Mapper* GetDefault(void)
      {
        return GetByName(L"");
      }

      /// Retrieves and returns a pointer to a mapper object that does nothing and affects no
      /// controller elements. Can be used as a fall-back in the event of an error. Always returns a
      /// valid address.
      /// @return Pointer to the null mapper object.
      static const Mapper* GetNull(void);

      /// Checks if a mapper of the specified name is known and registered.
      /// @param [in] mapperName Name of the mapper to check.
      /// @return `true` if it is registered, `false` otherwise.
      static inline bool IsMapperNameKnown(std::wstring_view mapperName)
      {
        return (nullptr != GetByName(mapperName));
      }

      /// Returns a copy of this mapper's element map.
      /// Useful for dynamically generating new mappers using this mapper as a template.
      /// @return Copy of this mapper's element map.
      inline UElementMap CloneElementMap(void) const
      {
        return elements;
      }

      /// Returns a read-only reference to this mapper's element map.
      /// Primarily useful for tests.
      /// @return Read-only reference to this mapper's element map.
      inline const UElementMap& ElementMap(void) const
      {
        return elements;
      }

      /// Retrieves and returns the capabilities of the virtual controller layout implemented by the
      /// mapper. Controller capabilities act as metadata that are used internally and can be
      /// presented to applications.
      /// @return Capabilities of the virtual controller.
      inline SCapabilities GetCapabilities(void) const
      {
        return capabilities;
      }

      /// Returns this mapper's force feedback actuator map.
      /// @return Copy of this mapper's force feedback actuator map.
      inline UForceFeedbackActuatorMap GetForceFeedbackActuatorMap(void) const
      {
        return forceFeedbackActuators;
      }

      /// Retrieves and returns the name of this mapper.
      /// @return Mapper name.
      inline std::wstring_view GetName(void) const
      {
        return name;
      }

      /// Maps from virtual force feedback effect magnitude component to physical force feedback
      /// actuator values.
      /// @param [in] virtualEffectComponents Virtual force feedback vector expressed as a magnitude
      /// component vector.
      /// @param [in] gain Gain modifier to apply as a scalar multiplier on all the physical
      /// actuator values.
      /// @return Physical force feedback vector expressed as a per-actuator component vector.
      ForceFeedback::SPhysicalActuatorComponents MapForceFeedbackVirtualToPhysical(
          ForceFeedback::TOrderedMagnitudeComponents virtualEffectComponents,
          ForceFeedback::TEffectValue gain = ForceFeedback::kEffectModifierMaximum) const;

      /// Maps from physical controller state to virtual controller state.
      /// Does not apply any properties configured by the application, such as deadzone and range.
      /// @param [in] physicalState Physical controller state from which to read.
      /// @param [in] sourceControllerIdentifier Opaque identifier of the physical controller
      /// associated with the state being mapped.
      /// @return Controller state object that was filled as a result of the mapping.
      SState MapStatePhysicalToVirtual(
          SPhysicalState physicalState, uint32_t sourceControllerIdentifier) const;

      /// Maps from physical controller state to virtual controller state in which the physical
      /// controller is completely neutral and possibly even disconnected. Does not apply any
      /// properties configured by the application, such as deadzone and range.
      /// @param [in] sourceControllerIdentifier Opaque identifier of the physical controller
      /// associated with the state being mapped.
      /// @return Controller state object that was filled as a result of the mapping.
      SState MapNeutralPhysicalToVirtual(uint32_t sourceControllerIdentifier) const;

    private:

      /// All controller element mappers.
      const UElementMap elements;

      /// All force feedback actuator mappings.
      const UForceFeedbackActuatorMap forceFeedbackActuators;

      /// Capabilities of the controller described by the element mappers in aggregate.
      /// Initialization of this member depends on prior initialization of #elements so it
      /// must come after.
      const SCapabilities capabilities;

      /// Name of this mapper.
      const std::wstring_view name;
    };
  } // namespace Controller
} // namespace Xidi
