
#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/Serialization/EditContextConstants.inl>

#include "RemoteGameSystemComponent.h"

namespace RemoteGame
{
    void RemoteGameSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<RemoteGameSystemComponent, AZ::Component>()
                ->Version(0)
                ;

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<RemoteGameSystemComponent>("RemoteGame", "[Description of functionality provided by this System Component]")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                        ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                        ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void RemoteGameSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("RemoteGameService"));
    }

    void RemoteGameSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("RemoteGameService"));
    }

    void RemoteGameSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void RemoteGameSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    RemoteGameSystemComponent::RemoteGameSystemComponent()
    {
        if (RemoteGameInterface::Get() == nullptr)
        {
            RemoteGameInterface::Register(this);
        }
    }

    RemoteGameSystemComponent::~RemoteGameSystemComponent()
    {
        if (RemoteGameInterface::Get() == this)
        {
            RemoteGameInterface::Unregister(this);
        }
    }

    void RemoteGameSystemComponent::Init()
    {
    }

    void RemoteGameSystemComponent::Activate()
    {
        RemoteGameRequestBus::Handler::BusConnect();
    }

    void RemoteGameSystemComponent::Deactivate()
    {
        RemoteGameRequestBus::Handler::BusDisconnect();
    }
}
