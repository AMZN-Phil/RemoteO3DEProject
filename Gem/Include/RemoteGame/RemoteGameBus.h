
#pragma once

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace RemoteGame
{
    class RemoteGameRequests
    {
    public:
        AZ_RTTI(RemoteGameRequests, "{F3EB11BA-95AF-4A46-AFCD-F0874A51F7F0}");
        virtual ~RemoteGameRequests() = default;
        // Put your public methods here
    };

    class RemoteGameBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using RemoteGameRequestBus = AZ::EBus<RemoteGameRequests, RemoteGameBusTraits>;
    using RemoteGameInterface = AZ::Interface<RemoteGameRequests>;

} // namespace RemoteGame
