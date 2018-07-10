cmake_minimum_required(VERSION 3.5)

project(IntensityProfile)

#-----------------------------------------------------------------------------
# Extension meta-information
set(EXTENSION_HOMEPAGE "http://slicer.org/slicerWiki/index.php/Documentation/Nightly/Extensions/IntensityProfile")
set(EXTENSION_CATEGORY "SlicerDevUOM")
set(EXTENSION_CONTRIBUTORS "Achintha Kondarage (University of Moratuwa)")
set(EXTENSION_DESCRIPTION "Slicer Extensions to display intensity levels of an 3D image")
set(EXTENSION_ICONURL "http://www.example.com/Slicer/Extensions/IntensityProfile.png")
set(EXTENSION_SCREENSHOTURLS "http://www.example.com/Slicer/Extensions/IntensityProfile/Screenshots/1.png")
set(EXTENSION_DEPENDS "NA") # Specified as a space separated string, a list or 'NA' if any

#-----------------------------------------------------------------------------
# Extension dependencies
find_package(Slicer REQUIRED)
include(${Slicer_USE_FILE})

#-----------------------------------------------------------------------------
# Extension modules
add_subdirectory(LineIntensityProfile)
## NEXT_MODULE

#-----------------------------------------------------------------------------
include(${Slicer_EXTENSION_GENERATE_CONFIG})
include(${Slicer_EXTENSION_CPACK})
