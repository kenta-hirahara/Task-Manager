add_library(task_management
            SHARED
            TaskManager.cpp)

target_include_directories(task_management
    PUBLIC ${PROJECT_SOURCE_DIR}/include
    )
