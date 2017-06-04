#include <CL/cl.h>
#include "opencl_target.h"

char *cl_errstr(cl_int err) {
    switch (err) {
    case CL_SUCCESS: return "CL_SUCCESS";
    case CL_DEVICE_NOT_FOUND: return "CL_DEVICE_NOT_FOUND";
    case CL_DEVICE_NOT_AVAILABLE: return "CL_DEVICE_NOT_AVAILABLE";
    case CL_COMPILER_NOT_AVAILABLE: return "CL_COMPILER_NOT_AVAILABLE";
    case CL_MEM_OBJECT_ALLOCATION_FAILURE: return "CL_MEM_OBJECT_ALLOCATION_FAILURE";
    case CL_OUT_OF_RESOURCES: return "CL_OUT_OF_RESOURCES";
    case CL_OUT_OF_HOST_MEMORY: return "CL_OUT_OF_HOST_MEMORY";
    case CL_PROFILING_INFO_NOT_AVAILABLE: return "CL_PROFILING_INFO_NOT_AVAILABLE";
    case CL_MEM_COPY_OVERLAP: return "CL_MEM_COPY_OVERLAP";
    case CL_IMAGE_FORMAT_MISMATCH: return "CL_IMAGE_FORMAT_MISMATCH";
    case CL_IMAGE_FORMAT_NOT_SUPPORTED: return "CL_IMAGE_FORMAT_NOT_SUPPORTED";
    case CL_BUILD_PROGRAM_FAILURE: return "CL_BUILD_PROGRAM_FAILURE";
    case CL_MAP_FAILURE: return "CL_MAP_FAILURE";
    case CL_MISALIGNED_SUB_BUFFER_OFFSET: return "CL_MISALIGNED_SUB_BUFFER_OFFSET";
    case CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST: return "CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST";
    case CL_COMPILE_PROGRAM_FAILURE: return "CL_COMPILE_PROGRAM_FAILURE";
    case CL_LINKER_NOT_AVAILABLE: return "CL_LINKER_NOT_AVAILABLE";
    case CL_LINK_PROGRAM_FAILURE: return "CL_LINK_PROGRAM_FAILURE";
    case CL_DEVICE_PARTITION_FAILED: return "CL_DEVICE_PARTITION_FAILED";
    case CL_KERNEL_ARG_INFO_NOT_AVAILABLE: return "CL_KERNEL_ARG_INFO_NOT_AVAILABLE";
    case CL_INVALID_VALUE: return "CL_INVALID_VALUE";
    case CL_INVALID_DEVICE_TYPE: return "CL_INVALID_DEVICE_TYPE";
    case CL_INVALID_PLATFORM: return "CL_INVALID_PLATFORM";
    case CL_INVALID_DEVICE: return "CL_INVALID_DEVICE";
    case CL_INVALID_CONTEXT: return "CL_INVALID_CONTEXT";
    case CL_INVALID_QUEUE_PROPERTIES: return "CL_INVALID_QUEUE_PROPERTIES";
    case CL_INVALID_COMMAND_QUEUE: return "CL_INVALID_COMMAND_QUEUE";
    case CL_INVALID_HOST_PTR: return "CL_INVALID_HOST_PTR";
    case CL_INVALID_MEM_OBJECT: return "CL_INVALID_MEM_OBJECT";
    case CL_INVALID_IMAGE_FORMAT_DESCRIPTOR: return "CL_INVALID_IMAGE_FORMAT_DESCRIPTOR";
    case CL_INVALID_IMAGE_SIZE: return "CL_INVALID_IMAGE_SIZE";
    case CL_INVALID_SAMPLER: return "CL_INVALID_SAMPLER";
    case CL_INVALID_BINARY: return "CL_INVALID_BINARY";
    case CL_INVALID_BUILD_OPTIONS: return "CL_INVALID_BUILD_OPTIONS";
    case CL_INVALID_PROGRAM: return "CL_INVALID_PROGRAM";
    case CL_INVALID_PROGRAM_EXECUTABLE: return "CL_INVALID_PROGRAM_EXECUTABLE";
    case CL_INVALID_KERNEL_NAME: return "CL_INVALID_KERNEL_NAME";
    case CL_INVALID_KERNEL_DEFINITION: return "CL_INVALID_KERNEL_DEFINITION";
    case CL_INVALID_KERNEL: return "CL_INVALID_KERNEL";
    case CL_INVALID_ARG_INDEX: return "CL_INVALID_ARG_INDEX";
    case CL_INVALID_ARG_VALUE: return "CL_INVALID_ARG_VALUE";
    case CL_INVALID_ARG_SIZE: return "CL_INVALID_ARG_SIZE";
    case CL_INVALID_KERNEL_ARGS: return "CL_INVALID_KERNEL_ARGS";
    case CL_INVALID_WORK_DIMENSION: return "CL_INVALID_WORK_DIMENSION";
    case CL_INVALID_WORK_GROUP_SIZE: return "CL_INVALID_WORK_GROUP_SIZE";
    case CL_INVALID_WORK_ITEM_SIZE: return "CL_INVALID_WORK_ITEM_SIZE";
    case CL_INVALID_GLOBAL_OFFSET: return "CL_INVALID_GLOBAL_OFFSET";
    case CL_INVALID_EVENT_WAIT_LIST: return "CL_INVALID_EVENT_WAIT_LIST";
    case CL_INVALID_EVENT: return "CL_INVALID_EVENT";
    case CL_INVALID_OPERATION: return "CL_INVALID_OPERATION";
    case CL_INVALID_GL_OBJECT: return "CL_INVALID_GL_OBJECT";
    case CL_INVALID_BUFFER_SIZE: return "CL_INVALID_BUFFER_SIZE";
    case CL_INVALID_MIP_LEVEL: return "CL_INVALID_MIP_LEVEL";
    case CL_INVALID_GLOBAL_WORK_SIZE: return "CL_INVALID_GLOBAL_WORK_SIZE";
    case CL_INVALID_PROPERTY: return "CL_INVALID_PROPERTY";
    case CL_INVALID_IMAGE_DESCRIPTOR: return "CL_INVALID_IMAGE_DESCRIPTOR";
    case CL_INVALID_COMPILER_OPTIONS: return "CL_INVALID_COMPILER_OPTIONS";
    case CL_INVALID_LINKER_OPTIONS: return "CL_INVALID_LINKER_OPTIONS";
    case CL_INVALID_DEVICE_PARTITION_COUNT: return "CL_INVALID_DEVICE_PARTITION_COUNT";
    case CL_INVALID_PIPE_SIZE: return "CL_INVALID_PIPE_SIZE";
    case CL_INVALID_DEVICE_QUEUE: return "CL_INVALID_DEVICE_QUEUE";
    default: return "UNKNOWN ERROR";
    }
}

#define CL_CHECK(funcname, errcode) do {        \
        if (errcode != CL_SUCCESS) {            \
            fprintf(stderr, "%s:%d ERROR: %s() %s\n", __FILE__, __LINE__, funcname, cl_errstr(errcode)); \
            abort();                                                    \
        }                                                               \
    } while (0)

#define CL_CALL(func, ...) do {                                         \
        cl_int __cl_err = CL_SUCCESS;                                   \
        __cl_err = func(__VA_ARGS__, );                                  \
        if (__cl_err != CL_SUCCESS) {                                   \
            fprintf(stderr, "%s:%d ERROR: OpenCL primitive failed: %s\n", __FILE__, __LINE__, #func ); \
            abort();                                                    \
        }                                                               \
    } while (0)

int main() {
    cl_int err;
    opencl_target target;
    opencl_target_init(&target);

    cl_context_properties properties[] = {
        CL_CONTEXT_PLATFORM, (cl_context_properties)(target.platform_id),
        0
    };

    cl_context context = clCreateContext(properties, 1, &(target.device_id), NULL, NULL, &err);
    CL_CHECK("clCreateContext", err);

    const char *kernel_source =
        "__kernel void simple_add(\n"
        "    global const int* A,\n"
        "    global const int* B,\n"
        "    global int* C)\n"
        "{\n"
        "    C[get_global_id(0)] = A[get_global_id(0)] + B[get_global_id(0)];\n"
        "}\n";

    cl_program program = clCreateProgramWithSource(context, 1, &kernel_source, NULL, &err);
    CL_CHECK("clCreateProgramWithSource", err);

    err = clBuildProgram (program, 1, &(target.device_id), "", NULL, NULL);
    CL_CHECK("clBuildProgram", err);

    cl_command_queue queue = clCreateCommandQueueWithProperties(context, target.device_id, NULL, &err);
    CL_CHECK("clCreateCommandQueue", err);

    int A[] = {1, 2, 3, 4};
    int B[] = {2, 3, 4, 5};
    int C[] = {0, 0, 0, 0};

    // Replace all below with a primitive like:
    // opencl_run(
    //     context, program, etc...
    //     "kernel_name",
    //     IN, bufA,
    //     INOUT, bufB,
    //     OUT, bufC
    // );

    size_t size = sizeof(int) * 4;

    cl_mem buffer_A = clCreateBuffer(context, CL_MEM_READ_WRITE | CL_MEM_COPY_HOST_PTR, size, A, &err);
    CL_CHECK("clCreateBuffer", err);
    cl_mem buffer_B = clCreateBuffer(context, CL_MEM_READ_WRITE | CL_MEM_COPY_HOST_PTR, size, B, &err);
    CL_CHECK("clCreateBuffer", err);
    cl_mem buffer_C = clCreateBuffer(context, CL_MEM_READ_WRITE | CL_MEM_COPY_HOST_PTR, size, C, &err);
    CL_CHECK("clCreateBuffer", err);

    cl_kernel kernel = clCreateKernel(program, "simple_add", &err);
    CL_CHECK("clCreateKernel", err);

    err = clSetKernelArg(kernel, 0, sizeof(cl_mem), &buffer_A);
    CL_CHECK("clSetKernelArg", err);
    err = clSetKernelArg(kernel, 1, sizeof(cl_mem), &buffer_B);
    CL_CHECK("clSetKernelArg", err);
    err = clSetKernelArg(kernel, 2, sizeof(cl_mem), &buffer_C);
    CL_CHECK("clSetKernelArg", err);

    const size_t worksize[] = {4};

    err = clEnqueueNDRangeKernel(queue, kernel, 1, NULL, worksize, NULL, 0, NULL, NULL);
    CL_CHECK("clEnqueueNDRangeKernel", err);

    err = clFinish(queue);
    CL_CHECK("clFinish", err);

    err = clEnqueueReadBuffer(queue, buffer_C, CL_TRUE, 0, size, C, 0, NULL, NULL);
    CL_CHECK("clEnqueueReadBuffer", err);

    for (int i = 0; i < 4; i++) {
        printf("%d + %d = %d\n", A[i], B[i], C[i]);
    }

    return 0;
}
