find_package(Opus REQUIRED)
find_package(SFML 2.4 COMPONENTS audio network system REQUIRED)

file(GLOB_RECURSE SRC_FILES
	"*.c"
	"*.h"
    "*.hpp"
    "*.cpp"
)

add_library(libvoip ${SRC_FILES})
target_link_libraries(libvoip ${SFML_LIBRARIES} ${OPUS_LIBRARIES})