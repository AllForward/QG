<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>User Login Success Page!</title>
</head>
<body>
<hr><br>
<body background="image/success.jpg"width="400",hight="200">
<font color="red"><h2>欢迎来到您的主页：<%=session.getAttribute("username") %>!</font></h2>
<h3>以下是您的个人信息</h3>
<%
 	out.println("用户名:"+session.getAttribute("username"));
%>
<br><br>
<font color="red"><a href="login.jsp">点击我</a>回到登陆主页！</font>
</body>
</html>
