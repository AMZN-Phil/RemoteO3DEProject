
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "RemoteGameSystemComponent.h"

namespace RemoteGame
{
    class RemoteGameModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(RemoteGameModule, "{1CFBD55B-9E34-454D-A256-DB891307A0F2}", AZ::Module);
        AZ_CLASS_ALLOCATOR(RemoteGameModule, AZ::SystemAllocator, 0);

        RemoteGameModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                RemoteGameSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<RemoteGameSystemComponent>(),
            };
        }
    };
}// namespace RemoteGame

AZ_DECLARE_MODULE_CLASS(Gem_RemoteGame, RemoteGame::RemoteGameModule)
