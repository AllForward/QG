<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>User Login Page</title>
</head>
<body>
<center>
<hr><br><font color="red"><h1>欢迎来到登陆首页!</h1></font><br>
<form action="do_login.jsp" method="get">
<br>
<h2>请输入您的相关信息:</h2><br>
<body background="image/time (2).jpg"width="800",hight="800">
<table width="300" height="180" border="5" bordercolor="#A0A0A0">
				<tr>
					<th>用户名：</th>
					<td><input type="text" name="username"></td>
				</tr>
				<tr>
					<th>密码：</th>
					<td><input type="text" name="password"></td>
				</tr>
				<tr>
					<td colspan="2" align="center">
					<input type="submit"value="登陆"> 
					<input type="button" value="注册" onclick="window.open('button.jsp')"> <!--点击注册则跳转到注册页面-->
					<input type="reset" value="重  置"></td>
				</tr>
</table>
</form>
</center>
</body>
</html>
