
#pragma once

#include <AzCore/Component/Component.h>

#include <RemoteO3DEProject/RemoteO3DEProjectBus.h>

namespace RemoteO3DEProject
{
    class RemoteO3DEProjectSystemComponent
        : public AZ::Component
        , protected RemoteO3DEProjectRequestBus::Handler
    {
    public:
        AZ_COMPONENT(RemoteO3DEProjectSystemComponent, "{17DCC77D-7183-40DF-9669-A21147D734CE}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        RemoteO3DEProjectSystemComponent();
        ~RemoteO3DEProjectSystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // RemoteO3DEProjectRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
