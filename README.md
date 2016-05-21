###UCLA Winter and Spring Quarters 2018
###Class: EE180D
###Professor: William J. Kaiser
###Authors: Alexander Graening and Jim Xu

Goal: Create a program to recognize and provide feedback on freethrow form that adapts to individual users. This will provide a step forward in adaptive automated coaching in sports and sports medicine. Our ideal system would be used by someone practicing freethrows as follows:
1. User would wear sensor/sensors strapped to the back of the hand and/or close to the elbow.
2. Upon preparing to take a freethrow, user would execute a simple gesture sequence that can easily be recognized. (Likely simply reliant on orientation with respect to gravity.)
3. User then takes a freethrow and observes the result. Based on the result (make, miss right, miss left, miss short, miss long), the user will provide a gesture indicating the actual result.
4. The system will compare the actual result to a predicted result based on collected data. If the two agree, the system will either say "good job" or provide a suggestion as to where your primary issue was. (Pay attention to your elbow, pay attention to your hand, pay attention to your jump, etc.)

We will build the system in a series of incremental steps:
1. Build a freethrow classifier:
	- Design a simple data collection program
	- Video and collect data for 60 freethrows
	- Hand-label the data
	- Observe waveforms and select features
	- Divide the collected data in half and train using the first half based on the selected features and observed results, then use the classifier to predict the results of the other half and compare the results with the observed results. (Do not move on from this step until 90%+ accuracy is achieved.)
2. Test using additional data from the same person.
	- Build test program and test this in the field.
	- Add secondary classifier that will isolate different features to determine the reason for a miss. (elbow, wrist, jump, etc.)
3. Polish and finalize system
	- If results are good, add interface for gesture labelling and automated feedback to increase size of training set
	- Add pruning algorithm to ensure the data set stays a manageable size and throws away non-ideal data samples.


Work log:
Thursday Week 1:
	Synchronize two SensorTiles with data collection program
	Create data collection program and script to collect multiple sets
Notes: Look into complementary filter (as what AP uses) to measure starting/ending angles.

Collect initial data:
	60 full motions

	x number of motions for each step
		- Shooting from above the head
		- Raising the ball
