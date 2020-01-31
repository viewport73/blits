# blits

#### How to build

Visual Studio solution is available at ```projects/msvc2017/Blits.sln```. After successful build the resulting executable
and all needed DLLs can be found in ```data``` directory. Note that precompiled third party libraries are only available
for x64 target.

### Controls

Input        | Action
-------------|-------
LMB drag     | Rotate camera
RMB drag     | Rotate 3D model
Scroll wheel | Zoom in/out
F1-F3        | Toggle analytical lights on/off


## Third party libraries

This project makes use of the following open source libraries:

- [Open Asset Import Library](http://assimp.sourceforge.net/)
- [stb_image](https://github.com/nothings/stb)
- [GLFW](http://www.glfw.org/)
- [GLM](https://glm.g-truc.net/)
- [D3D12 Helper Library](https://github.com/Microsoft/DirectX-Graphics-Samples/tree/master/Libraries/D3DX12)
- [glad](https://github.com/Dav1dde/glad) (used to generate OpenGL function loader)
- [volk](https://github.com/zeux/volk) (meta loader for Vulkan API)

## Included assets

All the assets used are from open source license, need to add their cerdits here (currently searching names of them)