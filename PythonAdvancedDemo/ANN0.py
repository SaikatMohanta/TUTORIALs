from sklearn import linear_model

# Create a linear regression object
reg = linear_model.LinearRegression()

# Training data
X = [[1], [2], [3], [4]]
y = [3, 5, 7, 9]

# Train the model
reg.fit(X, y)

# Make predictions
X_test = [[5], [6]]
y_pred = reg.predict(X_test)

print("Predictions:", y_pred)

