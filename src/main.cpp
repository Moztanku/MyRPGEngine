#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include "jac/main.hpp"
#include "jac/print.hpp"

auto run(jac::Arguments& /* arg */, jac::Arguments& /* env */) -> int
{
    glm::vec3 vec(1.0f, 2.0f, 3.0f);

    jac::print_debug(
        jac::make_message("vec + vec = ", vec.x + vec.x, vec.y + vec.y, vec.z + vec.z)
    );

    return 0;
}