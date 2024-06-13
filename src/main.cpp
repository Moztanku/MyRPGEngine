#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include "jac/main.hpp"
#include "jac/print.hpp"

#include "entt/entity/registry.hpp"

auto run(jac::Arguments& /* arg */, jac::Arguments& /* env */) -> int
{
    // glm::vec3 vec(1.0f, 2.0f, 3.0f);

    // jac::print_debug(
    //     jac::make_message("vec + vec = ", vec.x + vec.x, vec.y + vec.y, vec.z + vec.z)
    // );

    entt::registry registry;

    const entt::entity entity = registry.create();

    registry.emplace<glm::vec3>(entity, 1.0f, 2.0f, 3.0f);
    auto vec3 = registry.get<glm::vec3>(entity);

    jac::print_debug(
        jac::make_message("vec3 tied to entity: ", vec3.x, " ", vec3.y, " ", vec3.z)
    );

    return 0;
}