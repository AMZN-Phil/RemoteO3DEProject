
#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/Serialization/EditContextConstants.inl>

#include "RemoteO3DEProjectSystemComponent.h"

namespace RemoteO3DEProject
{
    void RemoteO3DEProjectSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<RemoteO3DEProjectSystemComponent, AZ::Component>()
                ->Version(0)
                ;

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<RemoteO3DEProjectSystemComponent>("RemoteO3DEProject", "[Description of functionality provided by this System Component]")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                        ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                        ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void RemoteO3DEProjectSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("RemoteO3DEProjectService"));
    }

    void RemoteO3DEProjectSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("RemoteO3DEProjectService"));
    }

    void RemoteO3DEProjectSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void RemoteO3DEProjectSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    RemoteO3DEProjectSystemComponent::RemoteO3DEProjectSystemComponent()
    {
        if (RemoteO3DEProjectInterface::Get() == nullptr)
        {
            RemoteO3DEProjectInterface::Register(this);
        }
    }

    RemoteO3DEProjectSystemComponent::~RemoteO3DEProjectSystemComponent()
    {
        if (RemoteO3DEProjectInterface::Get() == this)
        {
            RemoteO3DEProjectInterface::Unregister(this);
        }
    }

    void RemoteO3DEProjectSystemComponent::Init()
    {
    }

    void RemoteO3DEProjectSystemComponent::Activate()
    {
        RemoteO3DEProjectRequestBus::Handler::BusConnect();
    }

    void RemoteO3DEProjectSystemComponent::Deactivate()
    {
        RemoteO3DEProjectRequestBus::Handler::BusDisconnect();
    }
}
