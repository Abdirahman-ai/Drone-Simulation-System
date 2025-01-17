# Project - Drone Simulation System

in this project, we were able to simulate the behavior of the drone and robots. You will be able to set the pickup location and the final destination of the robot, and afterward the drone will come and pick up the robot toward their destination. Not only the transportation simulation but you will be able to decide what to do with the robot's behavior when the passenger arrived at ther destination or if the drone is too late to pickup.

This directory contains the support code needed to visualize the drone simulation system.

#### What is in this directory?
<ul>
  <li>  <code>README.md</code>
  <li>  <code>.gitignore</code>
  <li>  <code>app</code> folder, which contains:
    <ul>
      <li>  <code>graph_viewer</code> : producing graph visualization
      <li>  <code>transit_service</code> : visualization
    </ul>
  <li>  <code>libs</code> folder, which contains:
    <ul>
      <li>  <code>routing</code> : finding the paths
      <li>  <code>trainsit</code> : entities properties
    </ul>
  <li>  <code>dependencies</code>
</ul>

## Video Presentation Link
Coming soon....
## Getting Started

Here is a quick overview of how to run the visualization

    ```bash
    # Go to the project directory
    cd /path/to/repo/project
    
    # Build the project
    make -j
    
    # Run the project (./build/web-app <port> <web folder>)
    ./build/bin/transit_service 8081 apps/transit_service/web/
    ```
    
Navigate to http://127.0.0.1:8081 and you should see a visualization.

Navigate to http://127.0.0.1:8081/schedule.html and you should see a page to schedule the trips.

Below are instructions that detail how to build and run in several different environments.  


# Simulation

## Schedule
You will be able to schedule the robots for a ride in this page http://127.0.0.1:8081/schedule.html. 

Type passenger name, select start and end destination, and press `Schedule Trip` button to schedule a trip. 

Now go to 3D Visualization page and select the view of the entities on top right corner.

## 3D Visualization
You will be able to watch the simulation of the drone and the passenger here http://127.0.0.1:8081.

On top right corner, you can change your camera view into locking the entities.

### DOCKER 
docker run -it --rm -p 8081:8081 abdinahmen/team-010-31-project:latest

