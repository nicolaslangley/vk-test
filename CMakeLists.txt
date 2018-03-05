cmake_minimum_required(VERSION 3.0)
project (vulkan-test-app)
add_executable(vulkan-test-app main.cpp vk_app.cpp)
target_link_libraries(vulkan-test-app -std=c++11 -stdlib=libc++ -lglfw3 "-framework CoreVideo" "-framework Vulkan" "-framework IOKit" "-framework Cocoa" "-framework Carbon")

