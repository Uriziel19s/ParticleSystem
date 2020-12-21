#include <iostream>


#include <epoxy/gl.h>

#include <AGL3Window.hpp>
#include <camera.h>
#include "multithreadoverseer.h"
#include "openglparticlerenderer.h"
#include "particleemitter.h"
#include "particlesystem.h"
#include "particlegenerators.h"
#include "shader.h"

using namespace std;


class MyWin : public AGLWindow {
public:
    MyWin() {}
    MyWin(int _wd, int _ht, const char *name, int vers, int fullscr=0)
        : AGLWindow(_wd, _ht, name, vers, fullscr), lastMouseXPosition(_wd / 2.0f), lastMouseYPosition(_ht / 2.0f) {}
    virtual void KeyCB(int key, int scancode, int action, int mods);
    void MainLoop();
    void ScrollCB(double xp, double yp);
    void MousePosCB(double xp, double yp);
    void display();
private:
    Camera camera{glm::vec3(0.0f, 0.0f, 0.0f),
                glm::vec3(-3.0f, -3.0f, -3.0f),
                glm::vec3(0.0f, 1.0f, 0.0f)};
    float lastMouseXPosition;
    float lastMouseYPosition;
    float mouseSensivity = 0.1f;
};

void MyWin::display()
{

}


// ==========================================================================
void MyWin::KeyCB(int key, int scancode, int action, int mods) {
    AGLWindow::KeyCB(key,scancode, action, mods); // f-key full screen switch
    if ((key == GLFW_KEY_SPACE) && action == GLFW_PRESS) {
         // do something
    }
    if (key == GLFW_KEY_HOME  && (action == GLFW_PRESS)) {
         // do something
    }
}



void MyWin::ScrollCB(double xp, double yp)
{
    camera.changeProjection(static_cast<float>(yp));
}

void MyWin::MousePosCB(double xp, double yp)
{
    camera.rotateCamera(-(lastMouseYPosition - static_cast<float>(yp)) * mouseSensivity, -(lastMouseXPosition - static_cast<float>(xp)) * mouseSensivity);
    lastMouseXPosition = static_cast<float>(xp);
    lastMouseYPosition = static_cast<float>(yp);
    camera.updateView();
}

// ==========================================================================
void MyWin::MainLoop()
{
    Shader program("../../ParticleSys/app/simpleshader.vert", "../../ParticleSys/app/simpleshader.frag");
    program.use();
    ParticleSystem system(10000000, 11);
    OpenGLParticleRenderer renderer;
    auto emiter = std::make_shared<ParticleEmitter>(5);
    {
        auto position_generator = std::make_shared<SpherePositionGenerator>();
        position_generator->center_ = {0.0f, 0.0f, 0.0f};
        position_generator->radius_ = 1.0f;
        emiter->AddGenerator(position_generator);

        auto color_generator = std::make_shared<OneColorGenerator>();
        color_generator->color_ = {0.0f, 1.0f, 0.0f};
        emiter->AddGenerator(color_generator);

    }
    system.AddEmiter(emiter);
    system.Update(10000000);
    renderer.Generate(&system);
    renderer.Update();



    float speed = 0.2f;
    glm::vec3 startCameraPosition(-3.0f, -3.0f, -3.0f);

    glfwSetInputMode(win(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    ViewportOne(0, 0, wd, ht);
    camera.setCameraTarget(startCameraPosition);

    glEnable(GL_DEPTH_TEST);
    do
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        AGLErrors("main-loopbegin");
        // =====================================================        Drawing
        glm::mat4 view = camera.getView();
        glm::mat4 projection = camera.getProjection(wd, ht);
        glBindVertexArray(renderer.vao_);
        glUniformMatrix4fv(0, 1, GL_FALSE, &projection[0][0]);
        glUniformMatrix4fv(1, 1, GL_FALSE, &view[0][0]);
        camera.updateView();
        renderer.Render();
        AGLErrors("main-afterdraw");
        WaitForFixedFPS(1.0f/60.0f);
        glfwPollEvents();
        //glfwWaitEvents();

        glfwSwapBuffers(win()); // =============================   Swap buffers

        if (glfwGetKey(win(), GLFW_KEY_DOWN ) == GLFW_PRESS)
        {
            camera.rotateCamera(-speed,0);
        }
        if (glfwGetKey(win(), GLFW_KEY_UP ) == GLFW_PRESS)
        {
            camera.rotateCamera(speed,0);
        }
        if (glfwGetKey(win(), GLFW_KEY_RIGHT ) == GLFW_PRESS)
        {
            camera.rotateCamera(0,speed);
        }
        if (glfwGetKey(win(), GLFW_KEY_LEFT ) == GLFW_PRESS)
        {
            camera.rotateCamera(0,-speed);
        }
        if (glfwGetKey(win(), GLFW_KEY_W ) == GLFW_PRESS)
        {
            camera.forwardBackwardMove(-speed);
        }
        if (glfwGetKey(win(), GLFW_KEY_S ) == GLFW_PRESS)
        {
            camera.forwardBackwardMove(speed);
        }
        if (glfwGetKey(win(), GLFW_KEY_A ) == GLFW_PRESS)
        {
            speed=0.8f;
        } if (glfwGetKey(win(), GLFW_KEY_D ) == GLFW_PRESS)
        {
            speed = 0.02f;
        }if (glfwGetKey(win(), GLFW_KEY_M ) == GLFW_PRESS)
        {
        }


    } while( glfwGetKey(win(), GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
             glfwWindowShouldClose(win()) == 0 );
}



int main()
{
    MyWin win;
    win.Init(800, 800, "AGL3 example", 0, 33);
    win.MainLoop();
}





