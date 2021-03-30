# Monte Carlo Pricing Methods and Simulations

At the expiry date t = T the option price is known as a function of the current stock and the strike price. 

The essence of the Monte Carlo method is that we carry out a simulation experiment
by finding the solution of a stochastic differential equation (SDE) from time t = 0 to time t = T.

This process allows us to compute the stock price t = T and then the option price using the payoff function.

We carry out M simulations or draws by finding the solution of the SDE and we calculate price at t = T.

Finally, we calculate the discounted average of the simulated payoff.

Summerize, the process is:

1. Construct a simulation path of the underlying stock

2. Calculate the stock price at t = T

3. Calculate the call price at t = T (use the payoff function)

Execute steps 1-3 M times

4. Calculate the averaged call price t = T

5. Discount the price found in step 4 to t = 0

When the number of time and simulation are larger, it gives the more accurate result.
