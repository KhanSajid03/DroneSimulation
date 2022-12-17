# Project 4 - Team 4

Team Members:
Sajid Khan - Khan0680
Madhan Mohan - Mohan130
Dhruv Balasubramanian - Balas095
Apekshik Panigrahi - Panig013

YouTube video for our Project: 
https://youtu.be/3cnY9wuqTmU 


## What the project is about
The Drone Simulation System is an application that simulates a system where a drone picks up and drops off robots as per user requests. This system is analogous to Uber; the passengers in this case are the robots, given both a pick-up location and drop-off spot on the front-end scheduling page. There are also other entities—a car that roams around, helicopters (that can be spawned from the front-end) roam around like the car. 

## How to run the simulation
Docker:

Link to DockerHub: https://hub.docker.com/repository/docker/mohan130/mohan130-homework4

First make sure your machine has Docker installed.

To pull down the mohan130-homework4 image run:

docker pull mohan130-homework4

To run the container with the new image run:

docker run -it --rm -p 8081:8081 mohan130-homework4

Navigate to http://localhost:8081/schedule.html to view your simulation, and http://localhost:8081/schedule.html to schedule a trip.

GitHub:
Or you could just clone this project from GitHub with this link 
“https://github.umn.edu/umn-csci-3081-F22/Team-001-4-homework04.git”

Once the project is cloned, 

“cd /path/to/repo/project”

and once you are in the project directory, build the project with

“make -j”

and once the code correctly compiles and builds, run it with

“./build/bin/transit_service 8081 apps/transit_service/web/”

to see the running project open up a browser and go to “localhost:8081” to see the simulation. To schedule trips and interact with the simulation go to “localhost:8081/schedule.html” to be able to schedule trips for the simulation to visualize.

## What the simulation does
This simulation contains multiple entities, such as cars, drones, helicopters, robots, and recharge stations. The user can interact with this simulation by scheduling trips which will create a robot that will be picked up and transported by the drone, and also by adding helicopters that will fly randomly throughout the map.
As of now, the map of allowable pick-up and drop-off locations is restricted to the University of Minnesota campus, but in principle, the same mechanism could be applied to any region, given a 3D model of the desired region. 
On the front end of the application, there are two pages, for scheduling and displaying the simulation respectively. On the schedule page, the user can select the desired pick-up and drop-off location for a robot, as well as a routing algorithm (either Astar, DFS, or Dijkstra). On the simulation page, the user can watch the drone first Beeline to the robot, then follow a path—generated based on the selected routing algorithm—from the robot pick-up location to the desired destination.

## Extension
### What it does
The extension that our group implemented is a mechanism to track the drone’s battery level and automatically handle the task of recharging the drone. As the drone moves, the drone’s battery depletes. Before beginning a scheduled trip, the drone’s logic first checks if there is enough battery to travel the distance necessary to complete the trip. If not, the drone is first redirected to the closest recharge station—recharge stations are placed evenly throughout the map—then proceeds to complete the scheduled trip. As with reality, our feature forces the drone to prioritize different goals depending on the more pressing issue of delivery vs battery life.

### Why is it significantly interesting?
Of course, no practically feasible drone has an infinite battery supply. Hence it is important for any realistic delivery simulation to account for the drone’s limited battery capacity. Our extension adds a necessary element of realism to the simulation by adding a battery to the drone. Further, our extension includes a mechanism that automatically redirects the drone to a charging station when the battery is critical—while ensuring that the drone always has enough battery (and stations are spread out enough) such that the drone is always able to reach the battery station when necessary.

### How does it add to the existing work?
New procedures have been added to this project to implement a battery. Nonetheless, the drone’s baseline functionality remains intact. Recharge station entities have been added throughout the map signified as big battery towers. Whenever a trip is scheduled the drone will determine if it has enough battery to make the trip. If it does then it will work just as intended, otherwise, the drone will beeline to the nearest recharge station and charge up its battery. Once this process is complete the drone will continue its task of picking up and delivering the drone to its destination.

### Which design pattern was used?
The decorator design pattern was used as the drone already exists and is functional. The reason we chose to implement the decorator pattern is so that we could leave the drone’s functionality intact, simply appending the battery functionality to what’s already there. No code in the Drone class was altered to change functionality—following the O in SOLID (open to extension, closed to modification). All that was needed on the drone was new functionality, so a decorator was implemented to add in the logic required to navigate and function with a battery.

### Instruction to use this new feature
This new feature does not require any user interactions. This new feature can be observed when using the drone repeatedly. Over its trips its battery will decrease until it does not have enough to complete a trip, then the user can see the drone charge itself and continue working as a transporter. There are also outputs to the terminal window from which the program is run, allowing the user to see on the terminal—should they choose to do so—when the drone has insufficient battery and needs to be recharged, as well as when the battery is recharged and when the trip is successfully completed.

## Sprint Retrospective
The sprint was a good addition to the workflow for this project. Splitting up the work was successful at the beginning. After a while, the group lost some direction because of integration issues where code written by different people does not work well together. The next time this group uses the AGILE workflow, more paired programming should be used. Pair programming would alleviate some of the integration issues because when code is pushed there will be more than one person who understands how it works, thus making integration much easier later.

## UML
https://drive.google.com/file/d/105UEHd6nAE0Z1OkzL4gaZBEs57_rDnjO/view?usp=sharing

