#include <thread>

#include <core/outputstream.h>

#include <shapes/quad.h>

#include <window/window.h>


int main(int argc, char *argv[])
{
    ga::Window window("Test");

    std::shared_ptr<ga::Quad> quad = std::make_shared<ga::Quad>();

    ga::Vec4<ga::Vec3<float>> verts = {
        ga::Vec3<float>({-.75f, -.75f, 0.0f}),
        ga::Vec3<float>({.75f, -.75f, 0.0f}),
        ga::Vec3<float>({.75f, .75f, 0.0f}),
        ga::Vec3<float>({-.75f, .75f, 0.0f})};
    ga::Vec4<ga::Vec4<float>> colors = {
        ga::Vec4<float>({1.0f, 0.0f, 0.0f, 1.0f}),
        ga::Vec4<float>({0.0f, 1.0f, 0.0f, 1.0f}),
        ga::Vec4<float>({0.0f, 0.0f, 1.0f, 1.0f}),
        ga::Vec4<float>({1.0f, 1.0f, 0.0f, 1.0f})};
    
    //quad->setVertices(verts);
    quad->setColors(colors);
    quad->setXWidth(1.5f);
    quad->setYHeight(1.5f);
    quad->setCenter({0.0f, 0.0f, 0.0f});

    window.addRenderObject(quad);

    while(true)
    {
        window.tick();
        auto windowEvents = window.getWindowEvents();
        
        for(auto&& evt : windowEvents)
        {
            ga::debug() << ga::eventTypeToString(evt->getEventType()) << "\n";
        }

        if(window.isDestroyed())
        {
            ga::info() << "Goodbye\n";
            break;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }
}