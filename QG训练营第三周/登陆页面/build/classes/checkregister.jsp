<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="java.sql.*" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>判断用户注册的账号是否有错误</title>
</head>
<body>
	<%
	String driverName = "com.mysql.jdbc.Driver"; 
    //加载JDBC驱动
    String dbURL = "jdbc:mysql://localhost:3306; DatabaseName=用户登录界面"; 
    //连接服务器和数据库
    String userName = "root"; //默认用户名
    String userPwd = "guopei111666"; //密码
       Class.forName(driverName);
       Connection Conn = DriverManager.getConnection(dbURL, userName, userPwd);
       System.out.println("Connection Successful!");
       String name = request.getParameter("username");
       String pwd = request.getParameter("password");
       String sql="Insert into p_user(username,password) values(?,?)";
       PreparedStatement pstmt=Conn.prepareStatement(sql);
       pstmt.setString(1, name);
       pstmt.setString(2, pwd);
       int n = pstmt.executeUpdate();
       if(n == 1){%>数据插入成功！<br><%}  
       else{%>数据插入失败！<br><%}
	%>
	<br><br>
	<font color="red"><a href="login.jsp">点击我</a>回到主页！</font>
</body>
</html>