package ca.uwaterloo.JCLCudaAPI;

import java.util.ArrayList;

import ca.uwaterloo.JCLCudaAPI.Context;
import ca.uwaterloo.JCLCudaAPI.Device;
import ca.uwaterloo.JCLCudaAPI.Event;
import ca.uwaterloo.JCLCudaAPI.Kernel;
import ca.uwaterloo.JCLCudaAPI.Platform;
import ca.uwaterloo.JCLCudaAPI.Program;
import ca.uwaterloo.JCLCudaAPI.Queue;
import ca.uwaterloo.JCLCudaAPI.Program.BuildStatus;

public final class KernelInfo {

	final Platform platform;
	final Device device;
	final Context context;
	final Queue queue;
	final Event event;
	final Program program;
	final Kernel kernel;

	long argIdx = 0;
	
	final String name;
	final String source;

	public KernelInfo(final int platformId, final int deviceId, final String name, final String source) {
		assert platformId >= 0 && deviceId >= 0;
		assert name != null && !name.isEmpty() && source != null && !source.isEmpty();
		this.name = name;
		this.source = source;
		platform = new Platform(platformId);
		device = new Device(platform, deviceId);
		context = new Context(device);
		queue = new Queue(context, device);
		event = new Event();
		program = new Program(context, source);
		
		ArrayList<String> compilerOptions = new ArrayList<>();
	    BuildStatus buildStatus = program.build(device, compilerOptions);
	    if (buildStatus != BuildStatus.Success) {
	      String message = program.getBuildInfo(device);
	      System.out.printf(" > Compiler error(s)/warning(s) found:\n%s\n", message);
	      System.exit(1);
	    }
		
		kernel = new Kernel(program, name);
	}

	@Override
	public String toString() {
		return "KernelInfo [platform=" + platform + ", device=" + device + ", context=" + context + ", queue=" + queue
				+ ", event=" + event + ", program=" + program + ", kernel=" + kernel + ", name=" + name + ", source="
				+ source + "]";
	}

}
