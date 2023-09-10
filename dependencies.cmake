include(FetchContent)

FetchContent_Declare(
  avendish
  GIT_REPOSITORY  "https://github.com/josephlarralde/avendish"
  GIT_TAG         79e5ad260d45357bc24f3c074bb4dfc1db0c44ff
  GIT_PROGRESS    true
)
FetchContent_Populate(avendish)

set(CMAKE_PREFIX_PATH "${avendish_SOURCE_DIR};${CMAKE_PREFIX_PATH}")
find_package(Avendish REQUIRED)
