# blargh
A basic ECS implementation in C++, with an example!

# Basics
All projects have an **EntityManager** and **EntityProcessor**. Instantiate entities using the manager, and register systems to the processor, which act on entities created by the manager that you passed to the processor. A system acts on entities which have specific components attached to it, for example a *Position* and *Velocity* component for a *PhysicsSystem*. See the example folder for an example.
