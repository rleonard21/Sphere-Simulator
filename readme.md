# Sphere Simulator
This project is a C++ port of the Javascript-based simulator that I wrote
several years ago. The simulator is used for computing the flight path
of a spinning sphere through the atmosphere. The simulator iteratively
computes the net force, acceleration, velocity and position. The net force
is computed from the projectile weight, drag, and forces due to its rotation.
Each parameter is handled as a 3D vector, enabling the simulator to compute
3D flight paths. 

## Simulation Excerpts
I used this simulator to answer two questions: Will a projectile
go further with a head wind or a tail wind? If a projectile is launched
with the same initial energy every time, which weight projectile will
result in the farthest range?

#### Head Wind vs. Tail Wind
Below is the output of the simulator for a 3m/s head wind and a 3m/s
tail wind. The head wind results in the projectile landing almost 10 meters
further than it does with the tail wind. Therefore, we would expect a head
wind to be more beneficial than a tail wind.

This result makes sense, since the upward lift due to the backspin
of the projectile is dependent on its relative velocity to the wind.
With a head wind, the relative velocity is higher and therefore the
lift is larger. 

![Head Wind vs. Tail Wind](https://i.imgur.com/LooTbPj.png)


#### Constant Energy
Below is the output of the simulator for various projectile weights.
The initial velocity of each projectile was computed with respect to
the kinetic energy equation to maintain a constant energy of 1.95J.

Unsurprisingly, there is a happy medium between projectile weight
and initial velocity, even if the energy is constant. In one
extreme, a feather-weight projectile would be halted quickly by air
resistance. On the other hand, a cannonball-like projectile (at 
this energy) would barely move at all. 

![Constant Energy](https://i.imgur.com/WFA4Uk5.png)