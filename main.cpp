#include <iostream>
#include <vulkan/vulkan.h>
#define GLFW_INCLUDE_NONE
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

int main(int argc, const char * argv[])
{
  glfwInit();

  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  GLFWwindow* window = glfwCreateWindow(800, 600, "Vulkan window", nullptr, nullptr);

  VkInstance instance;
  VkResult result;
  VkInstanceCreateInfo info = {};
  uint32_t instance_layer_count;
  
  result = vkEnumerateInstanceLayerProperties(&instance_layer_count, nullptr);
  std::cout << instance_layer_count << " layers found!\n";
  if (instance_layer_count > 0) 
  {
      std::unique_ptr<VkLayerProperties[]> instance_layers(new VkLayerProperties[instance_layer_count]);
      result = vkEnumerateInstanceLayerProperties(&instance_layer_count, instance_layers.get());
      for (int i = 0; i < instance_layer_count; ++i) 
      {
          std::cout << instance_layers[i].layerName << "\n";
      }
  }
  
  const char * names[] = {"VK_LAYER_LUNARG_standard_validation"};
  info.enabledLayerCount = 1;
  info.ppEnabledLayerNames = names;
  
  result = vkCreateInstance(&info, NULL, &instance);
  std::cout << "vkCreateInstance result: " << result  << "\n";

  while(!glfwWindowShouldClose(window)) 
  {
      glfwPollEvents();
  }

  glfwDestroyWindow(window);

  glfwTerminate();
  
  vkDestroyInstance(instance, nullptr);
  return 0;
}
