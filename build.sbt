name := "JCLCudaAPI"

version := "1.0"
organization := "ca.uwaterloo.jclcudaapi"
scalaVersion := "2.11.7"
javacOptions ++= Seq("-source", "1.8", "-target", "1.8", "-Xlint")
javaOptions += "-Xmx8g -Dlib/jcuda/linux"

//unmanagedJars in Compile += file("lib/jcuda/linux/jcuda-0.6.5.jar")

initialize := {
  val _ = initialize.value
  if (sys.props("java.specification.version") != "1.8")
    sys.error("Java 8 is required for this project.")
}
