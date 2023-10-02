include(FetchContent)

FetchContent_Declare(
  avendish
  GIT_REPOSITORY  "https://github.com/josephlarralde/avendish"
  GIT_TAG         79e5ad260d45357bc24f3c074bb4dfc1db0c44ff
  #GIT_REPOSITORY  "https://github.com/celtera/avendish"
  #GIT_TAG         beecd9d442c2ac0e7b181385f076423fd999be83
  GIT_PROGRESS    true
)
FetchContent_Populate(avendish)

set(CMAKE_PREFIX_PATH "${avendish_SOURCE_DIR};${CMAKE_PREFIX_PATH}")
find_package(Avendish REQUIRED)
