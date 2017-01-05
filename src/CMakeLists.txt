find_package(Opus REQUIRED)
find_package(SFML 2.4 COMPONENTS audio network system REQUIRED)

file(GLOB_RECURSE SRC_FILES
	"*.c"
	"*.h"
    "*.hpp"
    "*.cpp"
)

add_library(voip ${SRC_FILES})
target_link_libraries(voip ${SFML_LIBRARIES} ${OPUS_LIBRARIES})
target_include_directories(voip PRIVATE ${SFML_INCLUDE_DIR} ${OPUS_INCLUDE_DIRS})