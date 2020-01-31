/*
 * Physically Based Rendering
 * Copyright (c) 2017-2018 Michał Siejak
 */

#if !(defined(ENABLE_OPENGL) || defined(ENABLE_VULKAN) || defined(ENABLE_D3D11) || defined(ENABLE_D3D12))
#error "At least one renderer implementation must be enabled via an appropriate ENABLE_* preprocessor macro"
#endif

#include <cstdio>
#include <string>
#include <memory>
#include <vector>

#include "application.hpp"

#include "../opengl.hpp"
#include "../vulkan.hpp"

static void printUsage(const char* argv0)
{
	const std::vector<const char*> flags = {
#if defined(ENABLE_OPENGL)
		"-opengl",
#endif
#if defined(ENABLE_VULKAN)
		"-vulkan",
#endif
	};

	std::fprintf(stderr, "Usage: %s [", argv0);
	for(size_t i=0; i<flags.size(); ++i) {
		std::fprintf(stderr, "%s%s", flags[i], i < (flags.size()-1) ? "|":"");
	}
	std::fprintf(stderr, "]\n");
}

static RendererInterface* createDefaultRenderer()
{
#if defined(ENABLE_OPENGL)
	return new OpenGL::Renderer;
#elif defined(ENABLE_VULKAN)
	return new Vulkan::Renderer;
#endif
}

static RendererInterface* createNamedRenderer(const std::string& flag)
{
#if defined(ENABLE_OPENGL)
	if(flag == "-opengl") {
		return new OpenGL::Renderer;
	}
#endif
#if defined(ENABLE_VULKAN)
	if(flag == "-vulkan") {
		return new Vulkan::Renderer;
	}
#endif
	return nullptr;
}

int main(int argc, char* argv[])
{
	RendererInterface* renderer = nullptr;

	if(argc < 2) {
		renderer = createDefaultRenderer();
	}
	else {
		renderer = createNamedRenderer(argv[1]);
		if(!renderer) {
			printUsage(argv[0]);
			return 1;
		}
	}

	try {
		Application().run(std::unique_ptr<RendererInterface>{ renderer });
	}
	catch(const std::exception& e) {
		std::fprintf(stderr, "Error: %s\n", e.what());
		return 1;
	}
}
