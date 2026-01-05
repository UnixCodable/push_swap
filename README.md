*This project has been created as part of the 42 curriculum by lbordana, aeuvrard.*

###  <span style="color:orange">Description</span>

#### <span style="color:#DAB1DA">Project presentation</span>
Push-Swap is an exercise that allows us to explore the concept of algorithms. 
We can already propose a definition of an algorithm: a description of a sequence of steps that allows us to obtain a result from elements provided as input.
We use them every day, for example when following a recipe. This concept is particularly important in our field, since coding is essentially the creation of algorithms.
This project addresses the concept of algorithm complexity. Indeed, a problem can be solved in different ways; complexity calculation is based on two concepts: time and space.
For example, let's say we want to get from point A to point B. We might take several side streets because we don't like the noise on the main road or because we need to stop at a friend's house before reaching our destination. Or we may choose to take the main avenue because we have an appointment at point B and don't want to be late, or because we are already tired and don't want to travel any further than necessary.
If we choose the first route, it will take us longer and we will travel further than if we choose the second route. The choice of route will depend on our objectives. This brings us to the goal of this project.

#### <span style="color:#DAB1DA">Goal</span>
The ultimate goal of this exercise is to sort a list of numbers given as arguments in ascending order.
There are two constraints. The first is a limit of two stacks, A and B, and the second is a limit on the number of moves that can be made to sort this list:  
<ul>
    <li> Push to the top of stack A/B.</li>  
	<li> Rotate the first element of A/B to the end of the list</li>  
    <li> Swap the first two elements of list A/B</li>  
    <li> Perform one of these actions in both stacks at the same time</li>  
</ul>

In order to achieve this goal, the exercise requires the use of a different algorithm depending on the disorder observed in the list of numbers. To clarify, here is an overview of our project.

#### <span style="color:#DAB1DA">Overview</span>
To sort the list given as an argument, we have developed four algorithms:  
<ul>
   <li> Simple: difficulty O(n2)</li>  
   <li> Medium: difficulty O(n√n)</li>  
   <li> Advanced in O(n log n)</li>  
   <li> Adaptive: chooses the most suitable algorithm based on the disorder of the list</li>  
</ul>  

Once the program is complete, you will see a benchmark that displays several pieces of information:  
<ul>
    <li> the number of operations performed</li>  
    <li> the algorithm used and its complexity</li>  
    <li> the number of operations performed</li>  
    <li> details of the number of operations for each movement</li>  
</ul>

Here are the instructions for running the program.

### <span style="color:orange">Instruction</span>
On a terminal, navigate to the Push_Swap folder. Then, to run the program, you can execute these commands:
```bash
make
./push_swap --simple --bench &(shuf --100 -n --500)
```
In this example, the program will use the simple algorithm, print the benchmark, and take a list of 100 numbers between 0 and 500.
To use the other algorithms, simply change the name of the algorithm. If you want the program to adapt according to the disorder rate, you must choose the adaptive algorithm.
If you do not enter the arguments correctly, the program will not run and an error message will appear.
To create our program, we consulted several resources.


### <span style="color:orange">Ressources</span>


#### <span style="color:#DAB1DA">References</span>
Each of these resources helped us understand algorithmic logic, particularly   how to determine its level of complexity.

“List of links”

In addition to the websites consulted, we relied on AI within a strict framework.

#### <span style="color:#DAB1DA">IA utilisation</span>
As mentioned above, its use was strictly limited. First, we always prioritized our own research and discussions with our peers before resorting to it. In addition, we used it as a “teacher” to better understand certain concepts or how certain algorithms work, without ever asking it for code.
In the next section, you will find our arguments for choosing each algorithm.


### <span style="color:orange">Aditional section</span>

#### <span style="color:#DAB1DA">Algorithms choices</span>

##### <span style="color:lightpink">Simple</span>

##### <span style="color:lightpink">Medium</span>
We chose Range based because it was the simplest to implement given the constraints of the exercise. Thanks to the root of n, it is possible to construct intervals in which we classify integers by sorting each interval starting with the largest integers.

##### <span style="color:lightpink">Complex</span>

##### <span style="color:lightpink">Alternative</span>
It was simply designed based on the disorder rate. We followed the instructions for the exercise, i.e., choosing the simple algorithm for a disorder rate below 0.2%, the medium algorithm for a disorder rate between 0.2% and 0.5%, and the complex algorithm for a disorder rate above 0.5%.