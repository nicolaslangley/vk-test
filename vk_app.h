#ifndef VK_APP_H
#define VK_APP_H

#include <vulkan/vulkan.h>
#include <vector>

class GLFWwindow;

VkResult CreateDebugReportCallbackEXT(VkInstance instance,
                                      const VkDebugReportCallbackCreateInfoEXT* pCreateInfo,
                                      const VkAllocationCallbacks* pAllocator,
                                      VkDebugReportCallbackEXT* pCallback);

void DestroyDebugReportCallbackEXT(VkInstance instance,
                                   VkDebugReportCallbackEXT callback,
                                   const VkAllocationCallbacks* pAllocator);

class App
{
public:
  void run();

private:
  // GLFW init function
  void init_window();

  // Vulkan init functions
  void init_vulkan();
  void create_instance();
  void pick_vulkan_device();
  bool is_device_suitable(VkPhysicalDevice device);
  std::vector<const char*> get_required_extensions();
  void setup_debug_callback();

  void main_loop();

  void cleanup();

private:
  VkDebugReportCallbackEXT m_debug_callback;
  GLFWwindow* m_window;
  VkInstance m_instance;
};

#endif // VK_APP_H
