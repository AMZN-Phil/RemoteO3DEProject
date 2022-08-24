
#pragma once

#include <AzCore/Component/Component.h>

#include <RemoteGame/RemoteGameBus.h>

namespace RemoteGame
{
    class RemoteGameSystemComponent
        : public AZ::Component
        , protected RemoteGameRequestBus::Handler
    {
    public:
        AZ_COMPONENT(RemoteGameSystemComponent, "{F2F9696D-4799-44C4-8127-E95CBEAD7E64}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        RemoteGameSystemComponent();
        ~RemoteGameSystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // RemoteGameRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
