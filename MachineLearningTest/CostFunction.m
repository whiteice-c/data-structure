%第一个练习：机器学习平方差代价函数

function J = CostFunc(X,y,theta)
	m = size(X,1);					 %训练集样本数
	predictions = X*theta;			%预测值
	squareError = (predictions-y).^2;	%计算平方差
	
	J = 1/(2*m)*sum(squareError);		%计算代价
	
	