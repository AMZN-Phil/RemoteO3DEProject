
#pragma once

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace RemoteO3DEProject
{
    class RemoteO3DEProjectRequests
    {
    public:
        AZ_RTTI(RemoteO3DEProjectRequests, "{EBA4E62E-4B04-47A7-BB36-3A4C90CD904F}");
        virtual ~RemoteO3DEProjectRequests() = default;
        // Put your public methods here
    };

    class RemoteO3DEProjectBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using RemoteO3DEProjectRequestBus = AZ::EBus<RemoteO3DEProjectRequests, RemoteO3DEProjectBusTraits>;
    using RemoteO3DEProjectInterface = AZ::Interface<RemoteO3DEProjectRequests>;

} // namespace RemoteO3DEProject
