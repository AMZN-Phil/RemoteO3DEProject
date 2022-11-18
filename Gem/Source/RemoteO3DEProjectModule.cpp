
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "RemoteO3DEProjectSystemComponent.h"

namespace RemoteO3DEProject
{
    class RemoteO3DEProjectModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(RemoteO3DEProjectModule, "{47CF378A-8D99-4A4D-A507-AF93A541B002}", AZ::Module);
        AZ_CLASS_ALLOCATOR(RemoteO3DEProjectModule, AZ::SystemAllocator, 0);

        RemoteO3DEProjectModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                RemoteO3DEProjectSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<RemoteO3DEProjectSystemComponent>(),
            };
        }
    };
}// namespace RemoteO3DEProject

AZ_DECLARE_MODULE_CLASS(Gem_RemoteO3DEProject, RemoteO3DEProject::RemoteO3DEProjectModule)
