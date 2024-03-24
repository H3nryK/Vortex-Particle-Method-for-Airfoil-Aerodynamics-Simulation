#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

// Define constants and fluid properties
const double rho = 1.225;   // Air density (kg/m^3)
const double nu = 1.48e-5;  // Air kinematic viscosity (m^2/s)

// Vortex particle data structure
struct VortexParticle {
    double x, y;       // Position
    double gamma;      // Circulation strength
    double vx, vy;     // Velocity

    VortexParticle(double x0, double y0, double gamma0)
        : x(x0), y(y0), gamma(gamma0), vx(0.0), vy(0.0) {}
};

// Function to calculate induced velocity at a point from a vortex particle
void calcInducedVelocity(double x, double y, const std::vector<VortexParticle>& particles, double& u, double& v) {
    u = v = 0.0;
    for (const auto& vp : particles) {
        double dx = x - vp.x;
        double dy = y - vp.y;
        double r2 = dx * dx + dy * dy;
        double r = std::sqrt(r2);
        double factor = vp.gamma / (2.0 * M_PI * r2);
        u += factor * (-dy);
        v += factor * dx;
    }
}

// Function to calculate lift coefficient from airfoil data (simplified example)
double calcLiftCoefficient(double alpha) {
    return 2.0 * M_PI * alpha / 180.0;  // Thin airfoil approximation
}

int main() {
    // Initialize blade geometry and inflow conditions
    double chord = 1.0;       // Chord length of blade section
    double alpha = 5.0;       // Angle of attack (degrees)
    double vinf = 10.0;       // Freestream velocity (m/s)

    // Calculate circulation strength from airfoil data
    double cl = calcLiftCoefficient(alpha);
    double gamma = 0.5 * vinf * cl * chord;   // Circulation strength

    // Create initial vortex particles at the trailing edge
    std::vector<VortexParticle> particles;
    particles.emplace_back(chord, 0.0, gamma);

    // Time-stepping loop
    double dt = 0.1;          // Time step size
    double t = 0.0;
    double tmax = 10.0;       // Total simulation time
    while (t < tmax) {
        // Update particle positions and velocities
        for (auto& vp : particles) {
            // Calculate induced velocity from all other particles
            double u, v;
            calcInducedVelocity(vp.x, vp.y, particles, u, v);

            // Update particle velocity and position
            vp.vx += u * dt;
            vp.vy += v * dt;
            vp.x += vp.vx * dt;
            vp.y += vp.vy * dt;
        }

        // Vortex shedding and particle creation
        if (static_cast<int>(t / 1.0) % 10 == 0) {
            particles.emplace_back(chord, 0.0, gamma);
        }

        t += dt;
    }

    // Separate wake and bound vortex particles
    std::vector<VortexParticle> wakeParticles;
    std::vector<VortexParticle> boundParticles;
    for (const auto& vp : particles) {
        if (vp.x > chord) {
            wakeParticles.push_back(vp);
        } else {
            boundParticles.push_back(vp);
        }
    }

    // Calculate lift and drag forces (simplified example)
    double lift = 0.0, drag = 0.0;
    for (const auto& vp : boundParticles) {
        lift += vp.gamma * vinf;
        drag += vp.gamma * vp.vy;
    }
    lift *= rho;
    drag *= rho;

    // Print forces and wake particle positions
    std::cout << "Lift force: " << lift << " N\n";
    std::cout << "Drag force: " << drag << " N\n";
    std::cout << "Wake particle positions:\n";
    for (const auto& vp : wakeParticles) {
        std::cout << "x = " << vp.x << ", y = " << vp.y << std::endl;
    }

    return 0;
}
